#pragma once

#ifndef ILIST_H
#define ILIST_H
#include <string>
using namespace std;

template<class T>
class IList {
public:
	virtual ~IList() {};

	virtual void add(T e) = 0;

    virtual void add(int index, T e) = 0;

    virtual void removeAt(int index) = 0;

    virtual void removeItem(T item) = 0;

    virtual bool empty() = 0;

    virtual int size() = 0;

    virtual void clear() = 0;

    virtual T get(int index) = 0;

    virtual int indexOf(T item) = 0;

    virtual bool contains(T item) = 0;

    virtual void toString() = 0;

};

#endif /* ILIST_H */