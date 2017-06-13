/*
 * DynamicStack.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: paulhabjanetz
 */


#include <iostream>
#include <string>

#include "DynamicStack.h"

using namespace std;

DynamicStack::~DynamicStack()
{
	StackNode *noPtr, *nextNode;

	noPtr = top;

	while (noPtr != NULL)
	{
		nextNode = noPtr->next;
		delete noPtr;
		noPtr = nextNode;
	}
}

void DynamicStack::push(int ID, char name[], int size1, char addy[], int size2, double average)
{
	StackNode *newNode;

	newNode = new StackNode;
	newNode->ID = ID;

	for (int j = 0; j < size1; j++)
	{
		newNode->name[j] = name[j];
	}
	for (int j = 0; j < size2; j++)
	{
		newNode->addy[j] = addy[j];
	}
	newNode->average = average;

	if (isEmpty())					// If the list is empty make the newNode the first node.
	{
		top = newNode;
		newNode->next = NULL;
	}
	else							// Otherwise, insert newNode before top
	{
		newNode->next = top;
		top = newNode;
	}

}

void DynamicStack::pop(StackNode &passNode)
{
	StackNode *temp;

	if (isEmpty())
	{
		cout << "The stack is empty!\n\n";
	}
	else
	{
		passNode.ID = top->ID;

		for (int j = 0; j < 20; j++)
		{
			passNode.name[j] = top->name[j];
		}

		for (int j = 0; j < 25; j++)
		{
			passNode.addy[j] = top->name[j];
		}

		passNode.average = top->average;

		temp = top->next;
		delete top;
		top = temp;
	}
}

bool DynamicStack::isEmpty()
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;

	return status;
}

