#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>

const int limit = 32;

using namespace std;

class STUDENT					// class for student info
{
private:
	long id;

public:
	STUDENT();
	STUDENT *next;				// point to next student

	void addID(int s);
	long getID();
};

STUDENT::STUDENT()				// constructor
{
	id = -1;
}

void STUDENT::addID(int s)		// function to add id to student
{
	id = s;
}


long STUDENT::getID()			// get ID and return
{
	return(id);
}


class linkedList
{
public:
	STUDENT *first;
	linkedList();
	void add(STUDENT *s);
	void print();
	STUDENT* search(int s);
};

STUDENT* linkedList::search(int s)
{
	STUDENT* cur;			// create pointer to student
	cur = first;			// set pointer to first student

	while(cur != NULL)		// go until end
	{
		if(s == cur->getID())	// if s = student id break
		{
			break;
		}
		cur = cur->next;	// otherwise continue search
	}
	return(cur);			// return pointer
}

linkedList::linkedList()	// establish empty list to NULL
{
	first=NULL;
}

void linkedList::add(STUDENT *s)
{
	STUDENT *cr;		 	// create a pointer for the student
	if(first == NULL)		// if the id is first in list put it so
	{
		first = s;
	}
	else					// otherwise loop through until you reach end
	{
		cr = first;

		while(cr->next != NULL)
		{
			cr = cr->next;
		}
		cr->next = s;		// place the student in the last available spot
	}
}

void linkedList::print()
{
	STUDENT *tm;			// create student pointer
	tm = first;				// establish the pointer to the first studetn

	while(tm != NULL)		// loop through list until NULL
	{
		cout << "\nID : " << tm->getID();	// ouput ID and then go to next
		tm = tm->next;
	}

}

class HASH
{
public:
	HASH();
	void add(STUDENT *s);
	void print();
	void search(int s);

private:
	int key(int s);
	linkedList *hs[limit];
};

void HASH::search(int s)
{
	linkedList *tm;			// create a pointer to the linked list inside the hash table
	tm = hs[key(s)];		// call the key function with value to be searched to find position of linked list

	STUDENT *st;			// create pointer to individual student
	st = tm->search(s);		// search the linked list position and storem in sm

	if(st == NULL)			// if not found
	{
		cout << "\nSorry we did not found it.\n";
	}
	else					// if found
	{
		cout << "\nWe found it.\n";
	}
}

HASH::HASH()
{
	for(int i=0;i<limit;i++)	// create linked list for the limit
	{
		hs[i] = new linkedList();
	}
}
int HASH::key(int s)			// multiplication function key for hash function
{
	double t;				 	// temp variable

	t = (sqrt(5.0)-1)/2;

	t = t * s;

	t = t - floor(t);

	t = t * limit;

	return(t);
}

void HASH::add(STUDENT *s)		// pass student info pointer
{
	hs[key(s->getID())]->add(s);	// request id of student and pass to key function.
									//as well pass the student info and insert in linked list
}
void HASH::print()					// print Function
{
	for(int i=0;i<limit;i++)
	{
		cout << "\n\nFor Table " << (i+1) << endl << endl;
		hs[i]->print();
	}
	cout << endl;
}

int main()				// start of main
{
	STUDENT *tmp;
	HASH hs;			// create hash and call constructor
	for(;;)
	{
		cout<<"\nWelcome to hash functioning "
				"process\n(1)Randomly add student information\n"
				"(2)Print each each cell in hash "
				"table\n(3)Search by ID \n(4)QUIT\n\nChoose [1 - 4]: ";

		int c;			// variable for choice

		do
				{
					cin >> c;			// read in input

					if(c < 1 || c > 4)
					{
						cout << "Wrong input, please put input 1 - 4: ";
					}
				}while(c<1 || c>4);

				switch(c)
				{
					case 1:					// For populating the random student info
					{
						string s;
						cout << "Press any key: ";	  // used incorporate user
						char id;
						cin >> id;

						for(int p = 0; p < 150; p++)  // loop and create 150 student records
						{
							tmp = new STUDENT();			// create new student object
							tmp->addID((100000 + rand()));	// populate that with an id
							tmp->next = NULL;				// set next to null
							hs.add(tmp);					// call function to add student to hash linked list
						}
						break;
					}
					case 2:						// print hash table
					{
						hs.print();
						break;
					}
					case 3:						// search for student
					{
						cout << "\nEnter the ID of the student: ";	// Request id

						int src;
						cin >> src;

						hs.search(src);			// call search function
						break;
					}
					case 4:
					{
						return (0);
						break;
					}
		}
	}
return 0;
}
