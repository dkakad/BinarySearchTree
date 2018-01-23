#include "bintree.h"

template class Node<int>;
template class bintree<int>;

template <typename T>
bintree<T>::bintree() {
	root = nullptr;
	height = 0;
}

template <typename T>
bintree<T>::bintree(Node<T>* newRoot) {
	root = newRoot;
	height = 0;
}

template <typename T>
Node<T>* bintree<T>::getRoot() {
	return root;
}

template <typename T>
void bintree<T>::setRoot(Node<T>* newRoot) {
	root = newRoot;
}

template <typename T>
int bintree<T>::getHeight() {
	return height;
}

template <typename T>
void bintree<T>::setHeight(int newHeight) {
	height = newHeight;
}


template <typename T>
void bintree<T>::addNode(Node<T>* newNode) {
	if (root == nullptr) {
		root = newNode;
		return;
	}
	Node<T> *pos = helperAdd(newNode, root);

	if (newNode->getData() < pos->getData()) {
		pos->setLeft(newNode);
	}
	else {
		pos->setRight(newNode);
	}
}

template <typename T>
Node<T>* bintree<T>::helperAdd(Node<T>* newNode, Node<T>* curr) {
	if (newNode->getData() < curr->getData()) {
		if (curr->getLeft() == nullptr) {
			return curr;
		}
		curr = curr->getLeft();
	}
	else {
		if (curr->getRight() == nullptr) {
			return curr;
		}
		curr = curr->getRight();
	}
	helperAdd(newNode, curr);
}

template <typename T>
bool bintree<T>::searchNode(Node<T> *findNode) {
	if (root == nullptr) {
		return false;
	}
	return helperSearch(findNode, root);
}

template <typename T>
bool bintree<T>::helperSearch(Node<T> *findNode, Node<T> *curr) {
	if (findNode->getData() == curr->getData()) {
		return true;
	}
	if (findNode->getData() < curr->getData()) {
		curr = curr->getLeft();
	}
	else {
		curr = curr->getRight();
	}
	if (curr == nullptr) {
		return false;
	}
	return helperSearch(findNode, curr);
}

template <typename T>
Node<T>* bintree<T>::getParent(Node<T> *child) {
	Node<T> *parent = root;
	if (root == nullptr) {
		return nullptr;
	}
	while (parent != nullptr) {
		if (parent->getLeft()->getData() == child->getData() || parent->getRight()->getData() == child->getData()) {
			break;
		}
		else {
			if (child->getData() < parent->getData()) {
				parent = parent->getLeft();
			}
			else {
				parent = parent->getRight();
			}
		}
	}
	return parent;
}

/*
 * Pseudo code for deletion of a node that has both left and right child.
 * 1) The succ is the largest node in the left subtree of deleted Node (or smallest
 *	  node in the right subtree of deleted Node. This code works for the former case).
 * 2) Get the succ.
 * 3) Break the succ from it's parent.
 * 4) Get the left subTree.
 * 5) Get the right subTree.
 * 6) Set succ as child of the delNode's parent (replace delNode with succ).
 * 7) Attach left subTree to succ.
 * 8) Attach right subTree to succ.
 * 9) Delete the delNode.
 */
template <typename T>
void bintree<T>::deleteNode(Node<T>* delNode) {
	if (!searchNode(delNode)) {
		printf("Cannot find node \n");
		return;
	}
	if (delNode->getLeft() == nullptr && delNode->getRight() == nullptr) {
		Node<T> *parent = getParent(delNode);
		if (parent->getLeft()->getData() == delNode->getData()) {
			parent->setLeft(nullptr);
		}
		else {
			parent->setRight(nullptr);
		}
		delete delNode;
	}
	else if (delNode->getLeft() == nullptr) {
		Node<T> *parent = getParent(delNode);
		Node<T> *succ = delNode->getRight();
		if (parent->getLeft()->getData() == delNode->getData()) {
			parent->setLeft(succ);
		}
		else {
			parent->setRight(succ);
		}
		delete delNode;
	}
	else if (delNode->getRight() == nullptr) {
		Node<T> *parent = getParent(delNode);
		Node<T> *succ = delNode->getLeft();
		if (parent->getLeft()->getData() == delNode->getData()) {
			parent->setLeft(succ);
		}
		else {
			parent->setRight(succ);
		}
		delete delNode;
	}
	else {
		Node<T> *parent = getParent(delNode);
		Node<T> *succ = delNode->getLeft();

		while (succ->getRight() != nullptr) {
			succ = succ->getRight();
		}
		Node<T> *succParent = getParent(succ);


		if (succParent->getLeft() == succ) {
			succParent->setLeft(nullptr);
		}
		else {
			succParent->setRight(nullptr);
		}

		Node<T> *leftTree = delNode->getLeft();
		Node<T> *rightTree = delNode->getRight();

		if (parent->getRight()->getData() == delNode->getData()) {
			parent->setRight(succ);
		}
		else {
			parent->setLeft(succ);
		}
		
		succ->setLeft(leftTree);
		succ->setRight(rightTree);
		delete delNode;
	}
}

template <typename T>
void bintree<T>::inOrder(Node<T> *travNode) {
	if (travNode != nullptr) {
		inOrder(travNode->getLeft());
		printf("Node = %d ", travNode->getData());
		if (travNode->getLeft() == nullptr) {
			printf("Left = NULL ");
		}
		else {
			printf("Left = %d ", travNode->getLeft()->getData());
		}

		if (travNode->getRight() == nullptr) {
			printf("Right = NULL \n");
		}
		else {
			printf("Right = %d \n", travNode->getRight()->getData());
		}
		inOrder(travNode->getRight());
	}
}

template <typename T>
void bintree<T>::preOrder(Node<T> *travNode) {
	if (travNode != nullptr) {
		printf("Node = %d ", travNode->getData());
		if (travNode->getLeft() == nullptr) {
			printf("Left = NULL ");
		}
		else {
			printf("Left = %d ", travNode->getLeft()->getData());
		}

		if (travNode->getRight() == nullptr) {
			printf("Right = NULL \n");
		}
		else {
			printf("Right = %d \n", travNode->getRight()->getData());
		}
		preOrder(travNode->getLeft());
		preOrder(travNode->getRight());
	}
}

template <typename T>
void bintree<T>::postOrder(Node<T> *travNode) {
	if (travNode != nullptr) {
		postOrder(travNode->getLeft());
		postOrder(travNode->getRight());
		printf("Node = %d ", travNode->getData());
		if (travNode->getLeft() == nullptr) {
			printf("Left = NULL ");
		}
		else {
			printf("Left = %d ", travNode->getLeft()->getData());
		}

		if (travNode->getRight() == nullptr) {
			printf("Right = NULL \n");
		}
		else {
			printf("Right = %d \n", travNode->getRight()->getData());
		}
		
	}
}

