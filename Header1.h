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
	LList<T>& Push(T content);
	void Print() const;
	void Remove(int index);
	int Number();
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
		a1 = a2;
	}
}

template <class T>
LList<T>& LList<T>::Push(T content) {
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
		cout << i << ") " << n->content << endl;
		n = n->pNext;
		i++;
	}
}

template <class T>
void LList<T>::Remove(int index) {
	int i = 1;
	Node* n;
	n = first;

	while (i < index) {
		cout << "Debug message: " << n << n->content << endl;
		n = n->pNext;
		i++;
	}
	if (i = index) {
		cout << "Now it's time to destroy! ";
	}
}

template <class T>
int LList<T>::Number() {
	int i = 1;
	Node* n;
	n = first;
	while (n != NULL) {
		n = n->pNext;
		i++;
	}
	return i;
}