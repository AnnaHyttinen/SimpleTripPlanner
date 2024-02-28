#pragma once
#include <iostream>
using namespace std;

template<class T>
class LList {
private:
	class Node {
	public:
		T content;
		Node* pNext;
		Node() : pNext(NULL) {}
		Node(T cont) : content(cont), pNext(NULL) {}
		Node(T cont, Node* next) : content(cont), pNext(next) {}
	};

	Node* first;
	Node* last;

public:
	LList();
	~LList();
	LList<T>& insertToEnd(T content);
	void Print() const;
};

template<class T>
LList<T>::LList() {
	first = NULL;
	last = NULL;
}

template<class T>
LList<T>::~LList() {
	Node* a1, * a2;

	a1 = first;
	while (a1 != NULL) {
		a2 = a1->pNext;
		delete a1;
		cout << "\nDeleted a node." << endl;
		a1 = a2;
	}
}

template <class T>
LList<T>& LList<T>::insertToEnd(T content) {
	Node* newnode = new Node(content);
	if (first == NULL)
		first = newnode;
	else
		last->pNext = newnode;
	last = newnode;

	return *this;
}

template <class T>
void LList<T>::Print() const {
	int i = 1;
	Node* n;
	n = first;
	while (n != NULL) {
		cout << i << ") " << *(n->content) << "This should print the content. " << endl << endl;
		n = n->pNext;
		i++;
	}
}

