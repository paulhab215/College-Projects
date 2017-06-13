/*
 * * Main.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: paulhabjanetz
 */

#include <iostream>
#include <vector>							//vector header
#include <iomanip>							//format header
#include <cstdlib>
#include <fstream>
#include <string>						//string header

#include "DynamicStack.h"

using namespace std;

struct Tests
{
	int score;
	Tests *next2;
};

struct 	LinkedList
{
	int ID;
	char name[20];
	double average;
	char addy[25];
	Tests *head;
	struct LinkedList *next;
};


	int main()
	{
		cout << "hello";

		int SIZE = 20, size1 = 20, size2 = 25, average;
		//create linked list in main and read in.
		//
		LinkedList stulist;
		LinkedList stuhead;

		stuhead = stulist;

		ifstream fin;
			fin.open("names.txt");

			if (fin.fail())							//fail-safe
			{
			    cout << "ERROR: Cannot open the file..." << endl;
			    exit(0);
			}


			for (int i = 0; i < SIZE; i++) 			//loop the students
			{
				fin >> stulist.ID;				//read in id

				fin.getline(stulist.name, 20, '-');	//read in name with delimiter

				fin.getline(stulist.addy, 25, '-');

				Tests *newNode, *previousnode;		//ptrs for linked list
				LinkedList *newLinked;

				for(int j = 4; j < 16; j++)			//run through tests
			    {
					newNode = new Tests;			//create new node

					if(j == 4)						//establish head
					{
						stulist.head = newNode;
						fin >> newNode->score;
						previousnode = newNode;
					}
					else if(j == 15)				//establish end node
					{
						previousnode->next2 = newNode;
						fin >> newNode->score;
						newNode->next2 = NULL;		//fill last spot with null
					}
					else
					{
						previousnode->next2 = newNode;
						fin >> newNode->score;
						previousnode = newNode;
					}
			    }
				newLinked = new LinkedList;			//create new node
				if (i == 19)
				{
					stulist.next = NULL;
				}
				else
				{
					stulist.next = newLinked;
				}
			}



		DynamicStack stack; 			// declare dynamic stack variable

		for(int r = 0; r < SIZE; r++)
		{
			average = 0;

			for(int w = 0; w < 10; w++)
			{
				average += stuhead.head->score;
				stuhead.head = stuhead.head->next2;
			}

			average = average/2;

			stack.push(stuhead.ID, stuhead.name, size1, stuhead.addy, size2, average);

		}
		//linklist = linkedlist->next;
		//}



		return 0;
	}

