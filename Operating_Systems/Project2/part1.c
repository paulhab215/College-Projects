/*Author: Paul Habjanetz (A00579084)
 *Operating Systems
 *
 *Part 1
 *
 *   */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

#define REDUCE 100000000

int inBuffer[BUFFER_SIZE];
int bufferCounter;


// two semaphores and lock

pthread_mutex_t mutex;
sem_t semFull;
sem_t semEmpty;

// thread id
pthread_t threadId;

//attributes of the thread
pthread_attr_t threadAttributes;

/* Thread Functions */ 

void *producerThread(void* thread_args);
void *consumerThread(void* thread_args);


/* Producer function */
void *producerThread(void* thread_args) {

    int value;
    
    do {
    int sleeptime = rand()/REDUCE;

    //cause thread to sleep temporarily with random number
    //this will not cause an overflow to the screen
    sleep(sleeptime);

    value = rand()%1000; // assign random value to 1000

    /* Acquire empty semaphore */
    sem_wait(&semEmpty);

    /* Acquire mutex lock*/
    pthread_mutex_lock(&mutex);
    

    (insert_item(value));
	
     printf("\nValue %d produced by the producer",value);

    /* Release mutex */
    pthread_mutex_unlock(&mutex);

    /* Update full */
    sem_post(&semFull); 
 
  }while(1);

}


/* consumer function */
void *consumerThread(void* thread_args) {

    int value;

    do {
    /* Get a random number */
    int ranNum  = rand()/REDUCE;    
    

     /* Acquire full */
     sem_wait(&semFull);
   
     /* Acquire mutex */
     pthread_mutex_lock(&mutex);

	if(remove_item(&value)){
		fprintf(stderr, "Error reported by the Consumer Thread");
	}
	else{
		printf("\nValue %d is consumed", value);
	}

    /* Release mutex */
    pthread_mutex_unlock(&mutex);

    /* Update empty */
    sem_post(&semEmpty); 
 
  }while(1);

}

/*insert item into buffer*/

int insert_item(int threadValue){
	// if buffer is not ful than insert into buffer
	if(bufferCounter < BUFFER_SIZE){
		// assign the value to the buffer
		inBuffer[bufferCounter] = threadValue;
		
		bufferCounter++;
		return 0;
	}
	else{
		// if buffer is full
		return -1;
	}
}

/*remove item function*/

int remove_item(int *threadValue){
	if(bufferCounter > 0){  // if buffer has something in it than remove
		*threadValue = inBuffer[(bufferCounter-1)];
		
		// reduce counter by 1
		bufferCounter--;
		return 0;
	}
	else{
		// no element to be removed
		return -1;
	}

}


/*main function*/

int main(int argc, char *argv[]) {

  /* Seed time for rand() functions */
  srand(time(NULL));

  /* Necessary parameters */
  int time_sleep;
  int n_producers;
  int n_consumers;

// if not 4 args exit out
 if (argc != 4) {
    printf("Usage: ./executable time_to_sleep number_of_producers number_of_consumers\n");
    printf("All numbers should be integers.\n");
    exit(1);
  }
  else {    // if correct number of arguments pass on the variables
    time_sleep = atoi(argv[1]);
    n_producers = atoi(argv[2]);
    n_consumers = atoi(argv[3]);

    // output the data for user to see
    printf("Time program will  sleep: %d\n", time_sleep);
    printf("Number of producers: %d\n", n_producers);
    printf("Number of consumers: %d\n", n_consumers);
    printf("\n The screen will loop through buffer now: \n");
  }
 
 /* Set up the three semaphores: empty, full, and mutex. */

  // create the lock                         
  pthread_mutex_init(&mutex, NULL);
  
  //create the full semaphore - default value 0
  sem_init(&semFull, 0, 0);

  //create the empty semaphore and assignt to default value bufferSize
  sem_init(&semEmpty, 0, BUFFER_SIZE);

  //initialize the attributes
  pthread_attr_init(&threadAttributes);

  //intialize the buffer counter
  bufferCounter = 0;



  /* Create the producers */
  int i;
  for (i=0 ; i < n_producers ; i++) {

    int ret;
    ret = pthread_create(&threadId, &threadAttributes, producerThread, 
      NULL);

    if(ret) {
      printf("Error: pthread_create() returned %d\n", ret);
    }

  }

 /* Create the consumers */
  for (i=0 ; i < n_consumers ; i++) {

    int ret;
    ret = pthread_create(&threadId, &threadAttributes, consumerThread, 
      NULL);

    // verify being created right
    if(ret) {
      printf("Error: pthread_create() returned %d\n", ret);
    }

  }

  /* The threads are running. Sleep for user-specified time before exiting */
  sleep(time_sleep);

  printf("\nExecution is done.\n");
  return 0;


}

