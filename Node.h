#include <stdio.h>
#pragma once

template <typename T>
class Node {
	T data;
	Node<T> *left;
	Node<T> *right;
public:
	Node();
	Node(T newData);
	T getData();
	void setData(T newData);
	Node<T>* getLeft();
	Node<T>* getRight();
	void setLeft(Node<T> *newLeft);
	void setRight(Node<T> *newRight);
};