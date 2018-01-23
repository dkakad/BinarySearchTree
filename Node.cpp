#include "Node.h"

template <typename T>
Node<T>::Node() {
	data = NULL;
	left = nullptr;
	right = nullptr;
}

template <typename T>
Node<T>::Node(T newData) {
	data = newData;
	left = nullptr;
	right = nullptr;
}

template <typename T>
T Node<T>::getData() {
	return data;
}

template <typename T>
void Node<T>::setData(T newData) {
	data = newData;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
	return left;
}

template <typename T>
void Node<T>::setLeft(Node<T>* newLeft) {
	left = newLeft;
}

template <typename T>
Node<T>* Node<T>::getRight() {
	return right;
}

template <typename T>
void Node<T>::setRight(Node<T>* newRight) {
	right = newRight;
}