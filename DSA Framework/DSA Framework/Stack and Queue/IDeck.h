#pragma once
using namespace std;

template<class T>
class IDeck {
public:
	virtual ~IDeck() {};
	virtual T pop() = 0;
	virtual void push(T item) = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;
	// virtual T& peek() = 0;
	virtual bool remove(T item) = 0;
	virtual bool contains(T item) = 0;
	virtual void toString() = 0;
};