#pragma once
#include "IDeck.h"
#include "DLinkedList.h"
using namespace std;

template<class T>
class Stack : public IDeck<T> {
protected:
	DLinkedList<T> stackList;
public:
	Stack() { cout << "Created new Stack!\n"; }
	~Stack();

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
Stack<T>::~Stack() {
	this->stackList.~DLinkedList();
	cout << "Deleted the Stack!\n";
}

template<class T>
bool Stack<T>::empty(){
	return this->stackList.empty();
}

template<class T>
int Stack<T>::size() {
	return this->stackList.size();
}

template<class T>
void Stack<T>::clear() {
	return this->stackList.clear();
}

template<class T>
void Stack<T>::push(T item) {
	// Define: Add to tail -> pop from tail
	this->stackList.add(item);
}

template<class T>
T Stack<T>::pop() {
	// Define: Add to tail -> pop from tail
	if (this->empty()) return T();
	T resultItem = this->stackList.getTail()->data;
	this->stackList.removeAt(this->size() - 1);
	return resultItem;
}

//template<class T>
//T& Stack<T>::peek() {
//	if (this->empty) return T();
//
//}

template<class T>
bool Stack<T>::remove(T item) {
	if (this->size() == 0) return 0;
	int initSize = this->size();
	this->stackList.removeItem(item);
	int newSize = this->size();
	return (initSize - newSize == 1);
}

template<class T>
bool Stack<T>::contains(T item) {
	return this->stackList.contains(item);
}

template<class T>
void Stack<T>::toString() {
	if (this->size() == 0) {
		cout << "Size of the list: 0\nList: []\n";
	}
	else {
		this->stackList.toString();
		this->stackList.toString2();
	}
}