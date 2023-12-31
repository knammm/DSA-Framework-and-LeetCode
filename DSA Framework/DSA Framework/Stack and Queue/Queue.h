#pragma once
#include "IDeck.h"
#include "DLinkedList.h"
using namespace std;

template<class T> class Queue;

template<class T>
class Queue : public IDeck<T> {
protected:
	DLinkedList<T> queueList;
public:
	Queue() { cout << "Created a new Queue!\n"; }
	~Queue();

	T pop();
	void push(T item);
	bool empty();
	int size();
	void clear();
	//T& peek();
	bool remove(T item);
	bool contains(T item);
	void toString();
};

template<class T>
Queue<T>::~Queue() {
	this->queueList.~DLinkedList();
	cout << "Deleted the queue!\n";
}

template<class T>
T Queue<T>::pop() {
	// Define: Add to tail => pop from head
	if (this->size() <= 0) return T();
	T returnItem = this->queueList.getHead()->data;
	this->queueList.removeAt(0);
	return returnItem;
}

template<class T>
void Queue<T>::push(T item) {
	this->queueList.add(item);
}

template<class T>
bool Queue<T>::empty() {
	return this->size() == 0;
}

template<class T>
int Queue<T>::size() {
	return this->queueList.size();
}

template<class T>
void Queue<T>::clear() {
	this->queueList.clear();
}

template<class T>
bool Queue<T>::remove(T item) {
	int initSize = this->queueList.size();
	this->queueList.removeItem(item);
	int newSize = this->queueList.size();
	return (initSize - newSize == 1);
}

template<class T>
bool Queue<T>::contains(T item) {
	return this->queueList.contains(item);
}

template<class T>
void Queue<T>::toString() {
	this->queueList.toString();
	this->queueList.toString2();
}