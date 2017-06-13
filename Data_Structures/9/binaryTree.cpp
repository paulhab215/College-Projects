/*
 * binaryTree.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: paulhabjanetz
 */




#include <iostream>
#include <iomanip>
#include "BinaryTree.h"

using namespace std;



void StuBinaryTree::insertNode(int id, char stuname[], int size1, char stuaddy[], int size2, int arr[], int size3)
{
	TreeNode *newNode;

	newNode = new TreeNode;
	newNode->id = id;

	for (int j = 0; j < size1; j++)
	{
		newNode->name[j] = stuname[j];
	}
	for (int j = 0; j < size2; j++)
	{
		newNode->addy[j] = stuaddy[j];
	}

	Tests *newTests, *previousnode;
	for (int j = 0; j < size3; j++)
	{
		newTests = new Tests;
		if(j == 0)
		{
			newNode->head = newTests;
			newTests->score = arr[j];
			previousnode = newTests;
		}
		else if(j == 11)
		{
			previousnode->next = newTests;
			newTests->score = arr[j];
			newTests->next = NULL;
		}
		else
		{
			previousnode->next = newTests;
			newTests->score = arr[j];
			previousnode = newTests;
		}
	}

	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

void StuBinaryTree::destroySubTree(TreeNode *nodePtr)			//recurisviely calls itself and shreds the contents after it exhausts itself
{
	if(nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

void StuBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if (newNode->id < nodePtr->id)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

void StuBinaryTree::displayInOrder(TreeNode *nodePtr) const
{

	if (nodePtr)
	{
		displayInOrder(nodePtr->left);

		cout << endl << setw(5) << " ";					  // space filler
		cout << left << setw(12) << nodePtr->id;		  //output id
		cout << left << setw(24) << nodePtr->name;	  //output name
		cout << left << setw(25) << nodePtr->addy;	  //output addy
		cout << "Test Scores: ";
		for (int i = 0; i < 12; i++)
		{
			if (i == 11)
			{
				cout << nodePtr->head->score;
				nodePtr->head = nodePtr->head->next;
			}
			else
			{
				cout << nodePtr->head->score << ", ";
				nodePtr->head = nodePtr->head->next;
			}
		}
		displayInOrder(nodePtr->right);
	}
}

bool StuBinaryTree::searchNode(int num1, int num2)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if(nodePtr->id == num1)
		{
			if(nodePtr->right->id == num2)
			{
				cout << nodePtr->right->id << "   " << nodePtr->right->name << "  " << nodePtr->right->addy << "   ";
				cout << endl << nodePtr->id << "   " << nodePtr->name << "  " << nodePtr->addy << "   ";
				return true;

			}
			else if(nodePtr->left->id == num2 )
			{
				cout << nodePtr->left->id << "   " << nodePtr->left->name << "  " << nodePtr->left->addy << "   ";
				cout << endl << nodePtr->id << "   " << nodePtr->name << "  " << nodePtr->addy << "   ";
				return true;
			}
			else
			{
				cout << "Student with ID: " << num1 << " and student with ID: " << num2 << " cannot be found next to each other";
				return false;
			}
		}
		else if (num1 < nodePtr->id)
		{
			nodePtr = nodePtr->left;
		}
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

bool StuBinaryTree::removeNode(int toDelete)			// call twice with one number to remove node
{
	bool repeat;
	repeat = deleteNode(toDelete, root);
	return repeat;
}

bool StuBinaryTree::deleteNode(int num, TreeNode *&nodePtr)				// compare the number and delte the number in that category.
{
	if (num < nodePtr->id)							// if num is less then move on to smaller numbers in list
		deleteNode(num, nodePtr->left);
	else if(num > nodePtr->id)						// if num is greater then move on to larger numbers in list
		deleteNode(num, nodePtr->right);
	else if(num == nodePtr->id)
		makeDelete(nodePtr);
	else
	{
		cout << "Student with ID: " << num << " cannot be found - try again";
		return false;
	}
	return true;

}

void StuBinaryTree::makeDelete(TreeNode *&nodePtr)
{
	TreeNode *tempPtr;

	if (nodePtr == NULL)
		cout << "cannot delete empty node.\n";
	else if (nodePtr->left == NULL)
	{
		tempPtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempPtr;
	}
	else
	{
		tempPtr = nodePtr->right;
		while (tempPtr->left)
			tempPtr = tempPtr->left;
		tempPtr->left = nodePtr->left;
		tempPtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempPtr;
	}

}







