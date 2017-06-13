/*
 * Main.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: paulhabjanetz
 */

#include <iostream>							//normal header
#include <fstream>							//for file I/O
#include <vector>							//vector header
#include <iomanip>							//format header
#include <cstdlib>
#include <string>							//string header
using namespace std;

#include "StudentList.h"
#include "StudentList.cpp"


struct Student								//Struct for vector
{
	int id;
	char name[20];
	double gpa;
	char addy[25];
};

int main()
{
	int SIZE = 20, deleteed, in1, size1 = 20, size2 = 25;
	char in2[size1], in4[size2];
	double in3;

	Student individual[SIZE];

	cout << "hello";


	ifstream fin;
	fin.open("names.txt");

	if (fin.fail())							//fail-safe
	{
		cout << "ERROR: Cannot open the file..." << endl;
	    exit(0);
	}

	for (int i = 0; i < SIZE; i++) 					//loop the students
	{
		fin >> individual[i].id;					//read in id

		fin.getline(individual[i].name, 20, '-');	//read in name with delimiter

		fin >> individual[i].gpa;					//read in gpa

		fin.getline(individual[i].addy, 25, '-');
	}


	cout << "Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  \n\n"
		 << setw(5) << "";							// space filler
	cout << left << setw(12) << "STUDENT ID"; 		// set up formatted display template
	cout << left << setw(24) << "NAME";		  		// category name
	cout << left << setw(6) << "GPA";		  		// category GPA
	cout << left << setw(25) << "STUDENT ADDRESS";	// category Student address
	cout << endl;

	for(int k = 0; k < SIZE; k++)
	{
		cout << endl << setw(5) << " ";					  // space filler
		cout << left << setw(12) << individual[k].id;		  //output id
		cout << left << setw(24) << individual[k].name;	  //output name
		cout << left << setw(6) << individual[k].gpa;		  //output gpa
		cout << left << setw(25) << individual[k].addy;	  //output addy
	}

	cout << "\n\nNow lets create a linked list from this array.\n\n";

	StudentRecords firstList, secondList;

	for (int u = 0; u < SIZE; u++)
	{
		firstList.appendNode(individual[u].id, individual[u].name, size1, individual[u].gpa, individual[u].addy, size2);
	}

	firstList.displayList();

	for (int u = 0; u < SIZE; u++)
	{
		secondList.insertNode(individual[u].id, individual[u].name, size1, individual[u].gpa, individual[u].addy, size2);
	}

	secondList.displayList();

	cout << "\n\nEnter the ID you wish to Delete: ";
	cin >> deleteed;
	secondList.deleteNode(deleteed);

	cout << "\n\nHere is the list after deletion: \n";

	secondList.displayList();

	cout << "\n\nEnter the ID you wish to insert: ";
	cin >> in1;
	cout << "\n\nEnter the name you wish to insert: ";
	cin >> in2[size1];
	cout << "\n\nEnter the gpa you wish to insert: ";
	cin >> in3;
	cout << "\n\nEnter the address you wish to insert: ";
	cin >> in4[size2];

	secondList.insertNode(in1, in2, size1, in3, in4, size2);

	secondList.displayList();

	cout << "\n\n\n Thank you for joining us!\n\n" ;


	return 0;
}
