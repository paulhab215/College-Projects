#include <iostream>							//normal header
#include <fstream>							//for file I/O
#include <vector>							//vector header
#include <iomanip>							//format header
#include <cstdlib>
#include <string>							//string header
using namespace std;

struct Tests								//Linked List - test scores
{
		int score;
		Tests *next;						//pointer to next node
};

struct Student								//Struct for vector
{
	int id;
	char name[20];
	double gpa;
	char addy[25];
	Tests *head;
};

void quickSort(vector<Student> &, int, int); 	/// prototypes
int partition(vector<Student> &, int, int);
void swap(Student &, Student &);

vector<Student> myclass;				//declaration of vector


int main ()									//start of program
{
	int SIZE = 20,
		numc;

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

		fin >> classmate.gpa;				//read in gpa

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
			cout << left << setw(6) << myclass[k].gpa;		  //output gpa
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

	quickSort(myclass, 0, SIZE-1);

	cout << "\n\nHere is your list sorted by ID through Quicksort Recursion: " << endl << endl;

	cout << setw(5) << "";							// space filler
	cout << left << setw(12) << "STUDENT ID"; 		// set up formatted display template
	cout << left << setw(24) << "NAME";		  		// category name
	cout << left << setw(6) << "GPA";		  		// category GPA
	cout << left << setw(25) << "STUDENT ADDRESS";	// category Student address
	cout << endl << endl;

	for(int i = 0; i < SIZE; i++)
	{
		cout << setw(5) << " ";					 		 	//space filler
		cout << left << setw(12) << myclass[i].id;	//output info
		cout << left << setw(24) << myclass[i].name;
		cout << left << setw(6) << myclass[i].gpa;
		cout << left << setw(25) << myclass[i].addy;

		cout << "Test Scores: ";

		Tests *nodeptr;

		nodeptr = myclass[i].head;			//point to head of list

		while(nodeptr != NULL)						//traverse list and display
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
		cout << endl;

	}
	return 0;										//graceful exit
}


void quickSort(vector<Student> &people, int first, int last)	//quicksort function
{
	int pivotP;

	if (first < last)
	{
		pivotP = partition(people, first, last);		// call partition function

		quickSort(people, first, pivotP-1);		// quicksort for first

		quickSort(people, pivotP+1, last);		// quicksort for second
	}

}

int partition(vector<Student> &people, int first, int last)
{
	int pivotVal, pivotInd, midpoint;			// variable declaration

	midpoint = (first + last) / 2;				// establish mid

		swap(people[first], people[midpoint]);


		pivotInd = first;
		pivotVal = people[first].id;			// set variable to compare

		for(int scan = first + 1; scan <= last; scan++)	// loop thru variables
		{
			if(people[scan].id < pivotVal)
			{
				pivotInd++;
				swap(people[pivotInd], people[scan]);
			}
		}
		swap(people[first], people[pivotInd]);
		return pivotInd;
}


void swap(Student &value1, Student &value2)
{
	Student temp = value1;					// put one in temp

	value1 = value2;						// put two in one
	value2 = temp;							// put one in two
}
