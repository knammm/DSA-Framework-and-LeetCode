#pragma once
#include "IList.h"
#include <iostream>
using namespace std;

template<class T> class DLinkedList;

template<class T>
class DLinkedList : public IList<T> {
public:
	class Node;
protected:
	Node* head;
	Node* tail;
	int count = 0;
public:
	DLinkedList();
	~DLinkedList();

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
    void toString2();
    Node* getHead() { return this->head; }
    Node* getTail() { return this->tail; }

public:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
    public:
        Node(T data, Node* next = NULL, Node* prev = NULL) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
        Node(Node* next = NULL, Node* prev = NULL) {
            this->next = next;
            this->prev = prev;
        }
    };
};

template<class T>
DLinkedList<T>::DLinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

template<class T>
DLinkedList<T>::~DLinkedList() {
    this->clear();
}

template<class T>
void DLinkedList<T>::add(T e) {
    Node* newNode = new Node(e);
    // Case 1: No element
    if (this->count <= 0) {
        this->head = newNode;
        this->tail = newNode;
    }
    // Case 2: Add to tail
    else {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->count += 1;
}

template<class T>
void DLinkedList<T>::add(int index, T e) {
    if (index < 0 || index > this->count) return;

    if (this->count == 0) {
        this->add(e);
        return;
    }
    Node* newNode = new Node(e);
    // Case 1: Add head
    if (index == 0) {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    // Case 2: Add tail
    else if (index == count) {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    // Case 3: Others
    else {
        // Leverage the prev pointer of DLinkedList => 2 Case with O(N/2) => faster than SLinkedList
        if (index <= (this->count / 2)) {
            Node* ptr = this->head;
            for (int i = 0; i < this->count / 2; i++) {
                if (i == index - 1) {
                    newNode->prev = ptr;
                    newNode->next = ptr->next;
                    ptr->next->prev = newNode;
                    ptr->next = newNode;
                    break;
                }
                ptr = ptr->next;
            }
        }
        else {
            Node* ptr = this->tail;
            for (int i = this->count - 1; i >= this->count / 2; i--) {
                if (i == index - 1) {
                    newNode->prev = ptr;
                    newNode->next = ptr->next;
                    ptr->next->prev = newNode;
                    ptr->next = newNode;
                    break;
                }
                ptr = ptr->prev;
            }
        }
    }
    this->count += 1;
}

template<class T>
void DLinkedList<T>::toString() {
    cout << "Size of the List: " << this->size() << "\n";
    if (this->count <= 0) {
        cout << "[]\n";
        return;
    }

    cout << "Inverse List: [";
    Node* ptr = this->head;
    for (int i = 0; i < count - 1; i++) {
        cout << ptr->data << ", ";
        ptr = ptr->next;
    }
    cout << ptr->data << "]\n";
}

template<class T>
void DLinkedList<T>::toString2() {
    cout << "Size of the List: " << this->size() << "\n";
    if (this->count <= 0) {
        cout << "[]\n";
        return;
    }

    cout << "Reverse List: [";
    Node* ptr = this->tail;
    for (int i = 0; i < count - 1; i++) {
        cout << ptr->data << ", ";
        ptr = ptr->prev;
    }
    cout << ptr->data << "]\n";
}

template<class T>
void DLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= this->count || this->size() <= 0) return;
    Node* headPtr = this->head;
    Node* tailPtr = this->tail;
    Node* delPtr = NULL;
    // Case 1: Head
    if (index == 0) {
        delPtr = this->head;
        if (count == 1) {
            this->head = NULL;
            this->tail = NULL;
        }
        else {
            this->head = this->head->next;
            this->head->prev = NULL;
        }
        delPtr->next = NULL;
        delete(delPtr);
    }
    // Case 2: Tail
    else if (index == this->count - 1) {
        delPtr = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        delPtr->prev = NULL;
        delete(delPtr);
    }
    // Case 3: Others
    else {
        if (index <= (this->count / 2)) {
            for (int i = 0; i <= this->count / 2; i++) {
                if (i == index - 1) {
                    delPtr = headPtr->next;
                    headPtr->next = delPtr->next;
                    delPtr->next->prev = headPtr;
                    delPtr->next = NULL;
                    delPtr->prev = NULL;
                    break;
                }
                headPtr = headPtr->next;
            }
        }
        else {
            for (int i = this->count - 1; i >= this->count / 2; i--) {
                if (i == index + 1) {
                    delPtr = tailPtr->prev;
                    tailPtr->prev = delPtr->prev;
                    delPtr->prev->next = tailPtr;
                    delPtr->next = NULL;
                    delPtr->prev = NULL;
                    break;
                }
                tailPtr = tailPtr->prev;
            }
        }
        delete(delPtr);
    }
    this->count -= 1;
    return;
}

template<class T>
void DLinkedList<T>::removeItem(T item) {
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
        else {
            this->head = this->head->next;
            this->head->prev = NULL;
        }
        delPtr->prev = NULL;
    }
    // Case 2: Others
    else {
        while (ptr->next != NULL) {
            if (ptr->next->data == item) {
                delPtr = ptr->next;
                // Case tail
                if (delPtr == this->tail) {
                    this->tail = ptr;
                    ptr->next = NULL;
                }
                else {
                    ptr->next = delPtr->next;
                    delPtr->next->prev = ptr;
                }
                delPtr->next = NULL;
                delPtr->prev = NULL;
                break;
            }
            ptr = ptr->next;
        }
    }
    if (delPtr != NULL) {
        delete(delPtr);
        this->count -= 1;
    }
    return;
}

template<class T>
bool DLinkedList<T>::empty() {
	return this->count == 0;
}

template<class T>
int DLinkedList<T>::size() {
	return this->count;
}

template<class T>
void DLinkedList<T>::clear() {
	if (this->count <= 0) return;
	Node* ptr = this->head;
	Node* delPtr = NULL;

	while (ptr->next) {
		delPtr = ptr;
		ptr = ptr->next;
		delPtr->next = NULL;
        delPtr->prev = NULL;
		delete(delPtr);
	}
	delPtr = ptr;
    delPtr->prev = NULL;
	delete(delPtr);

	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

template<class T>
T DLinkedList<T>::get(int index) {
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
int DLinkedList<T>::indexOf(T item) {
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
bool DLinkedList<T>::contains(T item) {
	return (this->indexOf(item) != -1);
}