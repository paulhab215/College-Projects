# Project 2

# The Producer-Consumer Problem with Bounded Buffer.

In class, we discussed a semaphore-based solution to the producer-consumer problem using a bounded
buffer. In this project, you will write the Pthread code to solve this problem using three semaphores:
empty, full and mutex. 
You can assume the BUFFER_SIZE is 10 and you can use a circular queue to simulate the BUFFER. The
buffer will be manipulated with two functions, insert_item() and remove_item(), which are called by the 
producer and consumer threads, respectively. The insert_item() function will insert a random generated 
integer (between 0 and 1000) to the buffer and the remove_item() function will remove one integer from
the buffer. Busy waiting will apply if a producer or a consumer thread cannot enter its critical section.
The main() function will initialize the buffer and create the separate producer and consumer threads. Once 
it has created the producer and consumer threads, the main() function will sleep for a period of time and,
upon awakening, will terminate the whole program. The main() function will be passed three parameters
via the command line:
1. How long to sleep before terminating the program (in second).
2. The number of producer threads
3. The number of consumer threads
Hint: Refer to the Demo_Semaphore code for semaphore related operations.

In addition, please make
sure to print meaningful messages at the right stage such as:
The TA is helping student id.
Student id goes back to program. 
Student id waits for help in a chair.
The TA is sleeping.
The TA is waked up.

Hint: Refer to the Demo_Conditional_Var code if you decide to use conditional variables.

