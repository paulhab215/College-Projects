/*
 * StudentList.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: paulhabjanetz
 */


#include <iostream>							//normal header
#include <fstream>							//for file I/O
#include <iomanip>							//format header
#include <cstdlib>
#include <string>							//string header

#include "StudentList.h"

using namespace std;

void StudentRecords::appendNode(int id, char stuname[], int size1, double stugpa, char stuaddy[], int size2)
{
	StuList *newNode;
	StuList *nodePtr;



	newNode = new StuList;

	newNode->id = id;

	for (int j = 0; j < size1; j++)
	{
		newNode->name[j] = stuname[j];
	}

	newNode->gpa = stugpa;

	for (int j = 0; j < size2; j++)
	{
		newNode->addy[j] = stuaddy[j];
	}


	newNode->next = NULL;

	if (!headPtr)					// make newnode the first node if no other nodes
		headPtr = newNode;
	else
	{
		nodePtr = headPtr;			// Initialize nodePtr to head of list

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;	// FInd the last node in the list
		}

		nodePtr->next = newNode;			// Inser newNode as the last node.
	}
}

void StudentRecords::insertNode (int id, char stuname[], int size1, double stugpa, char stuaddy[], int size2)
{

	StuList *newNode;
	StuList *nodePtr;
	StuList *previousNode = NULL;

	newNode = new StuList;
	newNode->id = id;

	for (int j = 0; j < size1; j++)
	{
		newNode->name[j] = stuname[j];
	}

	newNode->gpa = stugpa;

	for (int j = 0; j < size2; j++)
	{
		newNode->addy[j] = stuaddy[j];
	}

	if (!headPtr)
	{
		headPtr = newNode;
		newNode->next = NULL;
	}
	else
	{
		nodePtr = headPtr;

		previousNode = NULL;

		while (nodePtr != NULL && nodePtr->id < newNode->id)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL)
		{
			headPtr = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void StudentRecords::deleteNode (int num)
{

	StuList *nodePtr;
	StuList *previousNode;

	if (!headPtr)					// make newnode the first node if no other nodes
			return;
	if(headPtr->id == num)
	{
		nodePtr = headPtr->next;
		delete headPtr;
		headPtr = nodePtr;
	}
	else
	{
		nodePtr = headPtr;

		while (nodePtr != NULL && nodePtr->id != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}



void StudentRecords::displayList () const
{
	StuList *nodePtr;

	nodePtr = headPtr;

	cout << "Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  \n\n"
			 << setw(5) << "";							// space filler
	cout << left << setw(12) << "STUDENT ID"; 		// set up formatted display template
	cout << left << setw(24) << "NAME";		  		// category name
	cout << left << setw(6) << "GPA";		  		// category GPA
	cout << left << setw(25) << "STUDENT ADDRESS";	// category Student address
	cout << endl;

	while(nodePtr->next != NULL)
	{
		cout << endl << setw(5) << " ";					  // space filler
		cout << left << setw(12) << nodePtr->id;		  //output id
		cout << left << setw(24) << nodePtr->name;	  //output name
		cout << left << setw(6) << nodePtr->gpa;		  //output gpa
		cout << left << setw(25) << nodePtr->addy;	  //output addy

		cout << "Test Scores: ";

		TestScores *testPtr;							//create ptr to test scores
		testPtr = nodePtr->head;				//point to head

		while(testPtr != NULL)					//traverse list and display
		{
			if(testPtr->next == NULL)
			{
				cout << testPtr->score;
				testPtr = testPtr->next;
			}
			else
			{
				cout << testPtr->score << ", ";
				testPtr = testPtr->next;
			}
		}
		nodePtr = nodePtr->next;
	}
}

StudentRecords::~StudentRecords()
{
	StuList *nodePtr, *nextNode;

	nodePtr = headPtr;

	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
}

