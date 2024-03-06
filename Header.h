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
    T& GetReference(int index);
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
    cout << endl;

    while (n != NULL) {
        cout << i << ") " << n->content << endl;
        n = n->pNext;
        i++;
    }
}

template <class T>
void LList<T>::Remove(int index) {
    int i = 1;
    Node* n = first;
    Node* previous = first;

    while (i < index) {
        previous = n;
        n = n->pNext;
        i++;
    }
    if (i = index) {
        cout << n->content << " destroyed! " << endl;
        if (index == 1) {
            first = n->pNext;
            delete n;
        }
        else {
            previous->pNext = n->pNext; // 1st index will not do
            delete n;
        }
    }
}

template <class T>
T& LList<T>::GetReference(int index) {
    int i = 1;
    Node* n = first;
    Node* previous = first;

    while (i < index) {
        previous = n;
        n = n->pNext;
        i++;
    }
    if (i = index) {
        T cont = n->content;
        return cont;
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
    return i-1;
}


template<typename T>
class Vector {
    T* arr;
    int capacity;
    int current;
public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
        cout << "Created a Vector" << endl;
    }
    ~Vector() { delete[] arr; }

    void Push(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void Print() {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
    }

    int Number() {
        int c = 0;
        for (int i = 0; i < current; i++) {
            c++;
        }
        return c;
    }
};
