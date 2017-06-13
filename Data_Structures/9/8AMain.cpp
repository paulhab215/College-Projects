/*
 * 8AMain.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: paulhabjanetz
 */

#include <iostream>
#include <vector>							//vector header
#include <iomanip>							//format header
#include <cstdlib>
#include <fstream>
#include <string>							//string header
using namespace std;

#include "BinaryTree.h"

struct Tests								//Linked List - test scores
{
		int score;
		Tests *next;						//pointer to next node
};

struct Student								//Struct for vector
{
	int id;
	char name[20];
	char addy[25];
	Tests *head;
};

vector<Student> myclass;				//declaration of vector


int main ()									//start of program
{

	int SIZE = 20, response1, response2, size1 = 20, size2 = 25, size3 = 12, arr[10];
	bool repeat;

	Student classmate;						//instance of struct

	ifstream fin;
	fin.open("names.txt");

	if (fin.fail())							//fail-safe
	{
	    cout << "ERROR: Cannot open the file..." << endl;
	    exit(0);
	}


	for (int i = 0; i < SIZE; i++) 			//loop the students
	{
		fin >> classmate.id;				//read in id

		fin.getline(classmate.name, 20, '-');	//read in name with delimiter

		fin.getline(classmate.addy, 25, '-');

		Tests *newNode, *previousnode;		//ptrs for linked list

		for(int j = 4; j < 16; j++)			//run through tests
	    {
			newNode = new Tests;			//create new node

			if(j == 4)						//establish head
			{
				classmate.head = newNode;
				fin >> newNode->score;
				previousnode = newNode;
			}
			else if(j == 15)				//establish end node
			{
				previousnode->next = newNode;
				fin >> newNode->score;
				newNode->next = NULL;		//fill last spot with null
			}
			else
			{
				previousnode->next = newNode;
				fin >> newNode->score;
				previousnode = newNode;
			}
	    }
		myclass.push_back(classmate);	//push instance into vector of structs
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
			cout << left << setw(12) << myclass[k].id;		  //output id
			cout << left << setw(24) << myclass[k].name;	  //output name
			cout << left << setw(25) << myclass[k].addy;	  //output addy

			cout << "Test Scores: ";

			Tests *nodeptr;							//create ptr to test scores
			nodeptr = myclass[k].head;				//point to head

			while(nodeptr != NULL)					//traverse list and display
			{
				if(nodeptr->next == NULL)
				{
					cout << nodeptr->score;
					nodeptr = nodeptr->next;
				}
				else
				{
					cout << nodeptr->score << ", ";
					nodeptr = nodeptr->next;
				}
			}
	}


	/// LOOP THROUGH VECTOR AND STORE THE INFORMATION IN BINARY TREE THROUGH INSERT FUNCTION


	StuBinaryTree tree;


	for (int u = 0; u < SIZE; u++)
	{
		for (int q = 0; q < 12; q++)
		{
			arr[q] = myclass[u].head->score;
			myclass[u].head = myclass[u].head->next;

		}
		tree.insertNode(myclass[u].id, myclass[u].name, size1, myclass[u].addy, size2, arr, size3);
	}

	cout << endl << endl;

	cout << "Here is the Binary Tree IN Order (ID, Name, GPA, Student Address, 10+ test scores):  \n\n"
		 << setw(5) << "";							// space filler
	cout << left << setw(12) << "STUDENT ID"; 		// set up formatted display template
	cout << left << setw(24) << "NAME";		  		// category name
	cout << left << setw(6) << "GPA";		  		// category GPA
	cout << left << setw(25) << "STUDENT ADDRESS";	// category Student address
	cout << endl;


	// DISPLAY VIA BINARY SEARCH AND HAVE IT SORTED

	tree.displayInOrder();



	// SEARCH FOR NODE BY ASKING FOR TWO ID NUMBERS THEN DISPLAY NODES - Two times

//
//	do
//	{
//		cout << "\n\nEnter first Student ID to search for: ";
//		cin >> response1;
//
//		cout << "\nEnter Student ID next to first ID to search for: ";
//		cin >> response2;
//
//		repeat = tree.searchNode(response1, response2);
//	}while (repeat != true);
//
//
//	do
//	{
//		cout << "\n\nEnter first Student ID to search for: ";
//		cin >> response1;
//
//		cout << "\nEnter Student ID next to first ID to search for: ";
//		cin >> response2;
//
//		repeat = tree.searchNode(response1, response2);
//	}while (repeat != true);

//
//	/// DELETE TWO NODES ONE AT AT TIME BY ASKING FOR TWO NUMBERS THEN DISPLAY SET
	do
	{
		cout << "\n\nEnter one Student's ID to delete: ";

		cin >> response1;

		repeat = tree.removeNode(response1);
	}while (repeat != true);

	tree.displayInOrder();

	do
	{
		cout << "\n\nEnter one Student's ID to delete: ";

		cin >> response1;

		repeat = tree.removeNode(response1);
	}while (repeat != true);

	tree.displayInOrder();

	return 0;
}
