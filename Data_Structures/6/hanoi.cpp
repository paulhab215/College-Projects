/*
 * hanoi.cpp
 *
 * Created on: Apr 5, 2014
 * Author: Paul Habjanetz
 *
 * Program Description: Shows step by step output of hanoi function.
 *
 */


#include <iostream>							// normal header

using namespace std;

void moveD(int a, char from, char aux, char to, char [], int);  // function prototype


int main()									// start of main
{

	     int n;								// variable for number of discs

	     cout << "\nWelcome to the monk inspired game: Tower of Hanoi\n\n";

	     cout << "Enter number of discs you would like to play with: ";  // prompt user

	     cin >> n;							// read in number

	     cout << "\n\n";					// formating

	     char arr[] = {'A', 'A', 'A', 'A', 'A'};	// declare array and initialize

	     moveD(n,'A','B','C', arr, n);		// call function

	return 0;								// exit function
}

void moveD(int a,char from,char aux,char to, char arr[], int number)
{
    if(a == 1)								// if statement for first disc
    {
       cout << "Move disc 1 from " << from << " to " << to << "\t\t";

       arr[0] = to;							// set spot one to necessary position

       if(number == 3)						// output for 3 discs
       {
           cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ")\n\n";
       }
       if(number == 4)						// output for 4 discs
       {
    	   cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ")\n\n";
       }
       if(number == 5)						// output for 5 discs
       {
    	   cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ")\n\n";
       }

       return;
    }
    else									// else statement for other amount
    {
       moveD(a-1,from,to,aux, arr, number);	// recursive call

       cout << "Move disc "<< a << " from " << from << " to "<< to << "\t\t";

       if(a == 2)
       {
       	   arr[1] = to;						// set spot one to necessary position
       }
       else if(a == 3)
       {
    	   arr[2] = to;						// set spot one to necessary position
       }

       else if(a == 4)
       {
    	   arr[3] = to;						// set spot one to necessary position
       }
       else
       {
    	   arr[4] = to;						// set spot one to necessary position
       }


       if(number == 3)						// output for 3 discs
       {
           cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ")\n\n";
       }
       if(number == 4)						// output for 4 discs
       {
    	   cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ")\n\n";
       }
       if(number == 5)						// output for 5 discs
       {
    	   cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ")\n\n";
       }

       moveD(a-1,aux,from,to, arr, number);	// recursive call
    }
}
