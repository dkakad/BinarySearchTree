#include "bintree.h"

int main() {
	bintree<int> *b = new bintree<int>();
	int a[15] = {50, 20, 70, 10, 30, 60, 80, 5, 15, 25, 40, 55, 65, 75, 90};
	for (int i = 0; i < 15; i++) {
		Node<int> *n = new Node<int>(a[i]);
		b->addNode(n);
	}
	Node<int>* n1 = b->getRoot()->getLeft()->getLeft();
	//b->deleteNode(n1);
	b->preOrder(b->getRoot());
	return 0;
}