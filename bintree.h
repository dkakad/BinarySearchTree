#include "Node.h"
#include "Node.cpp"
#pragma once

template <typename T>
class bintree {
	Node<T> *root;
	int height;
	Node<T>* helperAdd(Node<T>* newNode, Node<T>* curr);
	bool helperSearch(Node<T>* findNode, Node<T>* curr);
	Node<T> *getParent(Node<T> *child);
public:
	bintree();
	bintree(Node<T>* newRoot);
	Node<T>* getRoot();
	void setRoot(Node<T>* newRoot);
	int getHeight();
	void setHeight(int newHeight);
	void addNode(Node<T> *newNode);
	bool searchNode(Node<T> *findNode);
	void deleteNode(Node<T> *delNode);
	void inOrder(Node<T> *travNode);
	void preOrder(Node<T> *travNode);
	void postOrder(Node<T> *travNode);
};