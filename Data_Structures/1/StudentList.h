/*
 * StudentList.h
 *
 *  Created on: Apr 24, 2014
 *      Author: paulhabjanetz
 */

#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_

#include <iostream>

class StudentRecords
{
private:

	struct TestScores								//Linked List - test scores
	{
			int score;
			TestScores *next;						//pointer to next node
	};

	struct StuList
	{
		int id;
		char name[20];
		double gpa;
		char addy[25];
		TestScores *head;				// pointer to test scores
		struct StuList *next;
	};

	StuList *headPtr;			// List head pointer

public:
	StudentRecords()					// constructor - set to NULL
		{	headPtr = NULL;		}

	~StudentRecords();				// Destructor


	void appendNode (int, char[], int, double, char[], int);
	void insertNode (int, char[], int, double, char[], int);
	void deleteNode (int);
	void displayList () const;


};


#endif /* STUDENTLIST_H_ */
