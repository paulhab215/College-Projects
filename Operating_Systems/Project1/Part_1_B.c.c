/*

/*
 *
 * .c -- a fibanocci sequence (in win32)
 *  */
#include <stdio.h>
#include <windows.h>

int MAX_NUM = 1000;

DWORD sequence[];

/* the function to calculate values */

DWORD WINAPI fibonacci(LPVOID Arg)
{
	int i, first, second;
	first = 0;
	second = 1;

	DWORD Upper = *(DWORD*)Arg;
	for(i = 0; i <= Upper; i++){
		if(i <= 1){
			sequence[i] = i;
		}
		else{
			sequence[i] = first + second;
			first = second;
			second = sequence[i];
		}
	}

	printf("\nChild Complete");
	pthread_exit(0); /* exit */

}

int  main(int argc, char *argv[]) {

	DWORD ThreadId;
	HANDLE ThreadHandle;
	int i = 0;


	int n;

	if (argc != 2)
	{
		printf("Usage: %s n\n  where n is no. of #'s in sequence\n",argv[0]);
		return -1;
	}

    n = atoi(argv[1]); /* Get the number of the iterations */

	if ((n < 1) || (n > MAX_NUM))
	{
		printf("The no of numbers should between 1 and %d.\n",MAX_NUM);
		return -1;
	}
    /* Create the thread - default attributes, default stack, thread function, parameter, default creation flags*/

	ThreadHandle = CreateThread(NULL, 0, fibonacci, &n, 0, &ThreadId);


	/* Synchronize the completion of each thread. */
	if(ThreadHandle != NULL){
		WaitForSingleObject(ThreadHandle, INFINITE);

		CloseHandle(ThreadHandle);

		for(i =0; i <= n; i++)
                printf("\n%3d    %6d", i, sequence[i]);

	}
	printf("\nParent Complete");
}
