/*
 * main2a.cpp
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


int main ()									//start of program
{
	cout << "hello";
	int SIZE = 20;

	string studentID[20],studentName[20] ,studentAddr[20], studentstring;
	char *stustring;
	string studentGPA[20];

	ifstream fin;
	fin.open("names2a.txt");

	if (fin.fail())							//fail-safe
	{
	    cout << "ERROR: Cannot open the file..." << endl;
	    exit(0);
	}

stustring = new char();
	for (int i = 0; i < SIZE; i++) 			//loop the students
	{
		fin >> studentID[i]; 				//read in id

		fin.getline(stustring, 20, '-');	//read in name with delimiter
		studentName[i] = stustring;
		fin >> studentGPA[i];					//read in gpa

		fin.getline(stustring, 25, '-');
		studentAddr[i]=stustring;
	}

	cout << "Here are the current Students (ID, Name, GPA, Student Address):  \n\n"
		 << setw(5) << "";							// space filler
	cout << left << setw(12) << "STUDENT ID"; 		// set up formatted display template
	cout << left << setw(24) << "NAME";		  		// category name
	cout << left << setw(6) << "GPA";		  		// category GPA
	cout << left << setw(25) << "STUDENT ADDRESS";	// category Student address
	cout << endl;

	for(int k = 0; k < SIZE; k++)
	{

			cout << endl << setw(5) << " ";					  // space filler
			cout << left << setw(12) << studentID[k];		  //output id

			cout << left << setw(24) << studentName[k];		  //output id

			cout << left << setw(6) << studentGPA[k];		  //output id

			cout << left << setw(25) << studentAddr[k];		  //output id
	}

	studentStack stack(80);

	for(int w = 0; w < SIZE; w++)
	{
		stack.push(studentID[w]);
		stack.push(studentName[w]);
		stack.push(studentGPA[w]);
		stack.push(studentAddr[w]);
	}


	cout << "\n\nPopping 5 records - they are as follows: " << endl << endl;

	cout << setw(6) << "";							// space filler
	cout << left << setw(25) << "STUDENT ADDRESS"; 		// set up formatted display template
	cout << left << setw(7) << "GPA";		  		// category name
	cout << left << setw(24) << "NAME";		  		// category GPA
	cout << left << setw(12) << "STUDENT ID";	// category Student address
	cout << endl << endl;

	for(int d = 0; d < 5; d++)
	{
		for(int z = 0; z < 4; z++)
		{
			stack.pop(studentstring);
			if(z == 0)
			{
				cout << setw(5) << "";							// space filler
				cout << left << setw(25) << studentstring;
			}
			else if(z == 1)
			{
				cout << left << setw(6) << studentstring;
			}
			else if(z == 2)
			{
				cout << left << setw(24) << studentstring;
			}
			else
			{
				cout << left << setw(12) << studentstring;
			}
		}
		cout << endl;
	}

	stack.display();

	return 0;										//graceful exit
}

