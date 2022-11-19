#include "node.h"
#ifndef __slist_iterator__cpp__
#define __slist_iterator__cpp__
using namespace std;
template <class T>
class slist_iterator {
	node<T>* curr;//con tro tro vao node hien tai
public:
	slist_iterator() { curr = NULL; }
	slist_iterator(node<T>* p) { curr = p; }
	node<T>* getcurr() {
		return curr;
	}
	slist_iterator<T>& operator=(slist_iterator<T> p) {
		this->curr = p.getcurr();
		return *this;
	}
	bool operator!=(slist_iterator<T> p) {
		return curr != p.getcurr();
	}
	slist_iterator<T> operator++()//++curr
	{
		curr = curr->getnext();
		return curr;//tu dong ep kieu thanh iterator vi co ham tao co doi
	}
	slist_iterator<T> operator++(int)//curr++
	{
		node<T>* temp = curr;
		curr = curr->getnext();
		return temp;
	}
	T& operator*() {
		return curr->getelem();
	}
};
#endif