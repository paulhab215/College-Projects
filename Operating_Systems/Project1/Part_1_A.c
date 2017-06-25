

/* Paul Habjanetz
 * A00579084
 * 
 * .c -- Fibonacci Sequence (in pthread)
 *  */

 /* Necessary Headers */

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_NUM 1000

int sequence[]; //the array of numbers
int n;

 /* Runner Class - Solve Fib sequence */

void *fibonacci(void *arg)
{
	int i, first, second;
	first = 0;
	second = 1;

/* Loop through an populate Fib sequence */

	for(i = 0; i <= n; i++){
		if(i <= 1){
			sequence[i] = i;
		}
		else{	// add previous two elements to form new element
			sequence[i] = first + second;
			first = second;
			second = sequence[i];
		}
	}
	printf("\nChild Complete");
	pthread_exit(0); // exit completed child

}

/* Start of main */

int  main(int argc, char* argv[]) {

	// initial declarations of threads
	pthread_t tid;
	pthread_attr_t attr;


	int i = 0;	// create variable counter i
	if (argc != 2)
	{
		printf("Usage: %s n\n  where n is no. of #'s in sequence\n",argv[0]);
		return -1;
	}

        n = atoi(argv[1]); // get value of argv[1]

	if ((n < 1) || (n > MAX_NUM)) // check to make sure within bounds
	{
		printf("The no of numbers should between 1 and %d.\n",MAX_NUM);
		return -1;
	}

	pthread_attr_init(&attr); // get default attributes
	
	pthread_create(&tid, &attr, fibonacci, argv[1]); // create thread
	

	/* Synchronize the completion of each thread. */

	pthread_join(tid,NULL);
	
/* Output the fib sequence */

	for(i =0; i <= n; i++)
		printf("\n%3d    %6d", i, sequence[i]);
	printf("\nParent Complete\n");
}
