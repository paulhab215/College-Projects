

/*
 * Author: Paul Habjanetz
 * CS 4328 - Operating Systems
 * .c -- matrix multiplication (in pthread)
 */

/* Necessary Headers */

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

/* Define the constants used throughout program */

#define M 3
#define N 3
#define K 2

#define NUM_THREADS 10

/* Define the Matrices */

int B[M][K] = {{7,10},{8,11},{9,12}};
int A[K][N] = {{1,2,3},{4,5,6}};
int C[M][N];

/* structure for passing data to threads */

struct v
{
	int i; /* row */
	int j; /* column */
};

/* Function for multiplying the matrices */

void *multiply(void *arg)
{
	struct v *data = arg;
	int n, sum = 0;	// establish n for counter and the partial sum 

	/* Loop through the elements of A & B and multiply each adding to sum */
	for(n = 0; n <= K; n++){
		sum += A[data->i][n] * B[n][data->j];
	}

	C[data->i][data->j] = sum; // store in the appropriate C[][]
	

	pthread_exit(0);

}

/* Start of Main() */

int  main(int argc, char* argv[]) {

	int u, x; 		// counter variables
	pthread_attr_t attr;	// establish attributes  
	
	int numThreads = 0;	

	pthread_t tids[NUM_THREADS];
	
	/* Loop through and create the threads M x N */
	for(u = 0; u < M; u++){
		for(x = 0; x < N; x++){
			struct v *data = (struct v *) malloc(sizeof(struct v)); 

			data->i = u;
			data->j = x;

	/* Create the thread and initialize with default attributes */
			pthread_attr_init(&attr);		
			pthread_create(&tids[numThreads], &attr, multiply, data);
			
			numThreads++;
		}
	}

	/* Synchronize the completion of each thread. */
	
	for(u = 0; u < numThreads; u++)	
		pthread_join(tids[u], NULL);

	/* Output the contents of each part of C[][] */	
	for(u = 0; u < K; u++){
		for(x = 0; x < K; x++){
			printf("%d ", C[u][x]);
		}
		printf("\n");
	}	

	printf("\nParent Complete\n");
}
