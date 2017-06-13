/*
 * DynamicStack.h
 *
 *  Created on: Apr 23, 2014
 *      Author: paulhabjanetz
 */

#ifndef DYNAMICSTACK_H_
#define DYNAMICSTACK_H_

#include <iostream>
using namespace std;

class DynamicStack
{
private:

	struct StackNode
	{
		int ID;
		char name[20];
		double average;
		char addy[25];
		StackNode *next;
	};

	StackNode *top;


public:
	DynamicStack()
		{top = NULL;}

	~DynamicStack();

	void push(int, char [], int, char [], int, double);
	void pop(StackNode &);
	bool isEmpty();
};



#endif /* DYNAMICSTACK_H_ */
