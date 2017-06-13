/*
 * studentStack.h
 *
 *  Created on: Apr 27, 2014
 *      Author: ph1106
 */


#ifndef STUDENTSTACK_H_
#define STUDENTSTACK_H_
#include <string>							//string header

using namespace std;

class studentStack
{
private:
	string *stackArray;
	int stackSize;
	int top;

public:

	studentStack(int);
	studentStack(const studentStack &);

	~studentStack();

	void push(string);
	void pop(string &);
	void display();
};

#endif /* STUDENTSTACK_H_ */
