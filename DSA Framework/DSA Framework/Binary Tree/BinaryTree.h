#pragma once
#include<iostream>
#include "Stack.h"

template<class K, class V>
class BinaryTree : public IBTree<K, V> {
public:
	class Node;
protected:
	Node* pRoot;
	int count;
public:
	BinaryTree() {
		this->pRoot = NULL;
		this->count = 0;
		std::cout << "Created a new Binary Tree!\n";
	}

	~BinaryTree() {
		this->clear();
		std::cout << "Deleted the tree!\n";
	}

	void add(K key, V value = 0);
	V remove(K key);
	V search(K key);
	int size();
	int height();
	void clear();
	bool empty();

public:
	class Node {
	public:
		K key;
		V value;
		Node* pLeft;
		Node* pRight;
		int height;
	public:
		Node(K key, V value, Node* pLeft = NULL, Node* pRight = NULL) {
			this->key = key;
			this->value = value;
			this->pLeft = pLeft;
			this->pRight = pRight;
			this->height = 1;
		}

		~Node(){}

		void toString() {
			cout << "[Key: " << this->key << ", Value: " << this->value << ", Height: " << this->height << "]";
		}
	};
};

template<class K, class V>
void BinaryTree<K, V>::add(K key, V value) {
	// Define: Add from left to right.
}