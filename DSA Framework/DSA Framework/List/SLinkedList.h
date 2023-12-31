#pragma once

#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "IList.h"
#include <iostream>

using namespace std;

template<class T> class SLinkedList;
template<class T>
class SLinkedList : public IList<T> {
public:
	class Node;
protected:
	Node* head;
	Node* tail;
	int count;
public:
	SLinkedList();
	~SLinkedList();

	void add(T e);
    void add(int index, T e);
    void removeAt(int index);
    void removeItem(T item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    int indexOf(T item);
    bool contains(T item);
    void toString();

public:
    class Node {
    public:
        T data;
        Node* next;
    public:
        Node(T data, Node* next = 0) {
            this->data = data;
            this->next = next;
        }
        Node(Node* next = 0) {
            this->next = next;
        }
    };
};

template<class T>
SLinkedList<T>::SLinkedList() {
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

template<class T>
SLinkedList<T>::~SLinkedList() {
	this->clear();
}

template<class T>
void SLinkedList<T>::add(T e) {
	Node* newNode = new Node(e);
	if (this->head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->next = newNode;
		this->tail = newNode;
	}
	this->count += 1;
}

template<class T>
void SLinkedList<T>::add(int index, T e) {
	if (index < 0 || index > this->count) return;

	if (this->head == NULL) {
		this->add(e);
		return;
	}

	Node* newNode = new Node(e);
	// Case 1: Head
	if (index == 0) {
		newNode->next = this->head;
		this->head = newNode;
	}
	// Case 2: Tail
	else if (index == count) {
		this->tail->next = newNode;
		this->tail = newNode;
	}
	// Case 3: Parsing
	else {
		Node* ptr = this->head;
		for (int i = 0; i < count; i++) {
			if (i == index - 1) {
				newNode->next = ptr->next;
				ptr->next = newNode;
				break;
			}
			ptr = ptr->next;
		}
	}
	this->count += 1;
}

template<class T>
void SLinkedList<T>::toString() {
	cout << "Size of the List: " << this->size() << "\n";
	if (this->count <= 0) {
		cout << "[]\n";
		return;
	}

	cout << "List: [";
	Node* ptr = this->head;
	for (int i = 0; i < count - 1; i++) {
		cout << ptr->data << ", ";
		ptr = ptr->next;
	}
	cout << ptr->data << "]\n";
}

template<class T>
void SLinkedList<T>::removeAt(int index){
	if (index < 0 || index >= this->count || this->count <= 0) return;
	Node* ptr = this->head;
	// Case 1: Head
	if (index == 0) {
		if (count == 1) {
			this->head = NULL;
			this->tail = NULL;
		}
		else this->head = this->head->next;
		ptr->next = NULL;
		delete(ptr);
	}
	// Case 2: Tail
	else if (index == count - 1) {
		while (ptr->next != NULL) {
			if (ptr->next == this->tail) break;
			ptr = ptr->next;
		}
		Node* delPtr = this->tail;
		this->tail = ptr;
		ptr->next = NULL;
		delete(delPtr);
	}
	// Case 3: Others
	else {
		int counter = 0;
		Node* delPtr = NULL;
		while (ptr->next != NULL) {
			if (counter == index - 1) {
				delPtr = ptr->next;
				ptr->next = ptr->next->next;
				delPtr->next = NULL;
				break;
			}
			ptr = ptr->next;
			counter++;
		}
		delete(delPtr);
	}
	this->count -= 1;
}

template<class T>
void SLinkedList<T>::removeItem(T item) {
	if (this->count <= 0) return;
	Node* ptr = this->head;
	Node* delPtr = NULL;
	// Case 1: Head
	if (this->head->data == item) {
		delPtr = this->head;
		if (this->count == 1) {
			this->head = NULL;
			this->tail = NULL;
		}
		else this->head = this->head->next;
	}
	// Case 2: Others
	else {
		while (ptr->next != NULL) {
			if (ptr->next->data == item) {
				delPtr = ptr->next;
				// Case tail
				if (delPtr == this->tail) this->tail = ptr;
				ptr->next = ptr->next->next;
				break;
			}
			ptr = ptr->next;
		}
	}
	if (delPtr != NULL) {
		delPtr->next = NULL;
		delete(delPtr);
		this->count -= 1;
	}
	return;
}

template<class T>
bool SLinkedList<T>::empty() {
	return this->count == 0;
}

template<class T>
int SLinkedList<T>::size() {
	return this->count;
}

template<class T>
void SLinkedList<T>::clear(){
	if (this->count <= 0) return;
	Node* ptr = this->head;
	Node* delPtr = NULL;

	while (ptr->next) {
		delPtr = ptr;
		ptr = ptr->next;
		delPtr->next = NULL;
		delete(delPtr);
	}
	delPtr = ptr;
	delete(delPtr);

	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

template<class T>
T SLinkedList<T>::get(int index) {
	if (index < 0 || index >= count) return T();
	int counter = 0;
	Node* ptr = this->head;
	T returnData = this->head->data;
	while (ptr) {
		if (counter == index) {
			returnData = ptr->data;
			break;
		}
		ptr = ptr->next;
		counter++;
	}
	return returnData;
}

template<class T>
int SLinkedList<T>::indexOf(T item) {
	Node* ptr = this->head;
	int returnIndex = -1;
	for (int i = 0; i < count; i++) {
		if (ptr->data == item) {
			returnIndex = i;
			break;
		}
		ptr = ptr->next;
	}
	return returnIndex;
}

template<class T>
bool SLinkedList<T>::contains(T item) {
	return (this->indexOf(item) != -1);
}

#endif /* SLINKEDLIST_H */