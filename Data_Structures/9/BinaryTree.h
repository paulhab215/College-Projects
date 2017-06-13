/*
 * BinaryTree.h
 *
 *  Created on: Apr 23, 2014
 *      Author: paulhabjanetz
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class StuBinaryTree
{
private:



	struct Tests								//Linked List - test scores
	{
			int score;
			Tests *next;						//pointer to next node
	};

	struct TreeNode
	{
		int id;
		char name[20];
		double gpa;
		char addy[25];
		TreeNode *left;
		TreeNode *right;
		Tests *head;
	};


	TreeNode *root;

	void insert(TreeNode *&, TreeNode *&);
	void displayInOrder(TreeNode *) const;

	bool deleteNode(int, TreeNode *&);
	void makeDelete(TreeNode *&);
	void destroySubTree(TreeNode *);

public:

	StuBinaryTree()
		{	root = NULL;	}

	~StuBinaryTree()
		{	destroySubTree(root);	}

	void insertNode(int, char [], int, char [], int, int [], int);
	bool searchNode(int, int);
	bool removeNode(int);

	void displayInOrder() const
		{	displayInOrder(root);	}

};

#endif /* BINARYTREE_H_ */
