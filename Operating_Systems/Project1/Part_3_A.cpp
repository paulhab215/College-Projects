#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main()
{

	int count = 0, i;
	int size = 100000;
	int myArray [size];
	double start_time, end_time;
	
	//initialize random number generator
	srand((unsigned)time(NULL)); 

   //omp_set_num_threads(4);
   //omp_set_num_threads(8);
   #pragma omp parallel
   {
      #pragma omp single
          printf("Number of threads is %d\n",omp_get_num_threads());
   }

   for(i = 0; i < size; i++)
	myArray[i] = rand() % 100;
 
    
   start_time = omp_get_wtime();

   #pragma omp parallel for default(none) shared(size,myArray) private(i) reduction(+:count)
   for (i = 0; i < size; i++)
   {
		if (myArray[i] == 99){
			count++;
		}
    }	

    end_time = omp_get_wtime();

    printf ("The serial code indicates that there are %d 99s in the array.\n\n", count);
    printf ("The serial code used %f seconds to complete the execution.\n\n", end_time - start_time);

   return 0;

}
