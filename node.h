#ifndef __node__cpp__
#define __node__cpp__
#include <iostream>
using namespace std;

template<class T>
class node {
	T elem;
	node* next;
public:
	node() {
	}
	node(T x, node<T>* N = NULL) {
		elem = x;
		next = N;
	}
	void setelem(T x) {
		elem = x;
	}
	void setnext(node<T>* N = NULL) {
		next = N;
	}
	T& getelem() {
		return elem;
	}
	node<T>*& getnext() {
		return next;
	}
};
#endif
