#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 100000
#define THREADS 8
#define ITERATIONS SIZE/THREADS

int myArray[SIZE];
int counter = 0;

pthread_mutex_t counter_mutex;

void *count(void *tid)
{
	int i, first, *thistid, last;
	int local_count = 0;
	thistid = (int *)tid;

	first = (*thistid * ITERATIONS);
	last = first + ITERATIONS;
	
	printf("\nThread %d doing iteration %d to %d\n", *thistid, first, last-1);

	for(i = first; i < last; i++){
		 if (myArray[i] == 99){
                        local_count++;
                }
	}
	pthread_mutex_lock(&counter_mutex);
	counter = counter + local_count;
	pthread_mutex_unlock (&counter_mutex);
	pthread_exit(0);

}



int main()
{

	int i, start, tids[THREADS];
	struct timespec start_time, end_time;
	double total;
	
	pthread_t thread[THREADS];
	pthread_attr_t attr;

	pthread_mutex_init(&counter_mutex, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
		
	//initialize random number generator
	srand((unsigned)time(NULL)); 

   for(i = 0; i < SIZE; i++){
	myArray[i] = rand() % 100;
   }
   clock_gettime(CLOCK_MONOTONIC, &start_time);

 
   for (i = 0; i < THREADS; i++)
   {
	tids[i] = i;
	pthread_create(&thread[i], &attr, count, (void *)&tids[i]); 
   }	
   for(i =0; i< THREADS; i++){
	pthread_join(thread[i], NULL);

   }
   clock_gettime(CLOCK_MONOTONIC, &end_time);

   total = (end_time.tv_sec - start_time.tv_sec);
   total += (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    printf ("\nThe pthreads code indicates that there are %d 99s in the array.\n\n", counter);
    printf ("The pthreads code used %f seconds to complete the execution.\n\n", total);

   return 0;

}
