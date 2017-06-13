#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Tests
{
		char score[5];
		Tests *next;
};

int binarySearch(vector<vector<string> >, int, int, int);


int main ()
{
	int SIZE = 20,
		stuID,
		results;

	vector<vector<string> > Student;

	ifstream fin;
	fin.open("names.txt");

	if (fin.fail())
	{
	    cout << "ERROR: Cannot open the file..." << endl;
	    exit(0);
	}


	for (int i = 0; i < SIZE; i++) //loop your students
	{
		getline(fin, Student[i][0], '-');
		getline(fin, Student[i][1], '-');
		getline(fin, Student[i][2], '-');
		getline(fin, Student[i][3], '-');



		Tests *newNode, *head, *nodePtr;

		for(int j = 4; j < 13; j++)
	    {
			int temp = 0;
			newNode = new Tests;

			if(j = 4)
			{
				getline(fin, Student[i][j], '-');
				head = newNode;
				newNode->score = Student[i][j];
				newNode->next = NULL;
			}
			else
			{
				nodePtr = head;
				nodePtr = nodePtr->next;
				getline(fin, Student[i][j], '-');
				newNode->score = Student[i][j];
				nodePtr = nodePtr->next;
			}
	    }
	}

	cout << "Here are the current Students (ID, Name, GPA, Sudent Address, 10 test scores):  \n"
		 << setw(5) << "";	// space filler

	cout << left << setw(12) << "STUDENT ID"; // set up formatted display template
	cout << left << setw(24) << "NAME";		  // category name
	cout << left << setw(6) << "GPA";		  // category GPA
	cout << left << setw(25) << "STUDENT ADDRESS";	// category Stu
	cout << endl << endl;

	for(int k = 0; k < SIZE; k++)
	{
			cout << setw(5) << "";					  // space filler
			cout << left << setw(12) << Student[k][0];
			cout << left << setw(24) << Student[k][1];
			cout << left << setw(6) << Student[k][2];
			cout << left << setw(25) << Student[k][3];
			cout << endl;

			cout << "Test Scores: ";

			for(int j = 4; j < 13; j++)
			{
				cout << Student[results][j] << ", ";
			}
	}

	cout << "\n\nEnter the Student ID you wish to search for: ";
	cin >> stuID;

	cout << endl << endl;

	cout << "Here is your Student - found through Binary Recursion: " << endl << endl;

	results = binarySearch(Student, 0, SIZE-1, stuID); //// HOW DO you pass vector to a function.

	cout << setw(5) << " ";					 		 // space filler
	cout << left << setw(12) << Student[results][0];
	cout << left << setw(24) << Student[results][1];
	cout << left << setw(6) << Student[results][2];
	cout << left << setw(25) << Student[results][3];
	cout << endl;

	cout << "Test Scores: ";

	for(int l = 4; l < 13; l++)
	{
		cout << Student[results][l] << ", ";
	}


	return 0;
}

int binarySearch(vector<vector<string> > people, int first, int last, int value)
{
	int middle; //midpoint of search

	if (first > last)
		return -1;
	middle = (first + last) / 2;
	if (people[middle] == value)
		return middle;
	if (people[middle] < value)
		return binarySearch(people, middle+1, last, value);
	else
		return binarySearch(people, first, middle-1, value);
}
