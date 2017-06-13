/*
 * studentStack.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: ph1106
 */






#include <iostream>							//normal header
#include <fstream>							//for file I/O
#include <iomanip>							//format header
#include <cstdlib>
#include <string>							//string header

#include "studentStack.h"

using namespace std;

studentStack::studentStack(int size)
{
	stackArray = new string[size];
	stackSize = size;
	top = -1;
}

studentStack::studentStack(const studentStack &obj)
{
	if(obj.stackSize > 0)
		stackArray = new string[obj.stackSize];
	else
		stackArray = NULL;

	stackSize = obj.stackSize;

	for(int count = 0; count < stackSize; count ++)
		stackArray[count] = obj.stackArray[count];

	top = obj.top;
}


studentStack::~studentStack()
{
	delete [] stackArray;
}

void studentStack::push(string num)
{
	top++;
	stackArray[top] = num;
}

void studentStack::pop(string &num)
{
	num = stackArray[top];
	top--;
}

void studentStack::display()
{
     int t = top;


 	cout << "\n\nHere is your what is left on the stack after popping off 5 records " << endl << endl;

	cout << setw(1) << "";							// space filler
 	cout << left << setw(25) << "STUDENT ADDRESS"; 		// set up formatted display template
 	cout << left << setw(6) << "GPA";		  		// category name
 	cout << left << setw(24) << "NAME";		  		// category GPA
 	cout << left << setw(12) << "STUDENT ID";	// category Student address
 	cout << endl << endl;



     while( t != -1)
     {

          if (t % 4 == 1)
    	 {
				cout << left << setw(25) <<	stackArray[t];
    	 }
    	 if (t % 4 == 2)
    	 {
				cout << left << setw(6) << stackArray[t];
    	 }
    	 if (t % 4 == 3)
    	 {
				cout << left << setw(24) << stackArray[t];
    	 }
    	 if (t % 4 == 0)
    	 {
				cout << left << setw(12) << stackArray[t] << endl;;
    	 }

         t--;
     }
}


