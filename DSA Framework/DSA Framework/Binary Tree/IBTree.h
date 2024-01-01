#pragma once
using namespace std;

template<class K, class V>
class IBTree {
public:
	virtual ~IBTree() {};
	virtual void add(K key, V value = 0) = 0;
	virtual V remove(K key) = 0;
	virtual V search(K key) = 0;
	virtual int size() = 0;
	virtual int height() = 0;
	virtual void clear() = 0;
	virtual bool empty() = 0;
};