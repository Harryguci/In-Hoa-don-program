#ifndef DBLIST_H_
#define DBLIST_H_

#include <iostream>
#include <string>
#include <string.h>
#include "client.h"
#include "Node.h"

using namespace std;

template<class T>
class dlist_iterator
{
	node<T>* curr;

public:
	dlist_iterator(node<T>* c = 0);

	node<T>* getcurr();

	bool operator!=(dlist_iterator<T> it);

	T& operator*();

	dlist_iterator operator++(int);

	dlist_iterator operator++();
};

template<class T>
class dlist_reverse_iterator
{
	node<T>* curr;
public:
	dlist_reverse_iterator(node<T>* c = 0);
	node<T>* getcurr();
	dlist_reverse_iterator& operator=(dlist_reverse_iterator<T> it);
	bool operator!=(dlist_reverse_iterator<T> it);
	T& operator*();
	dlist_reverse_iterator operator++(int);
	dlist_reverse_iterator operator++();
};

template <class T>
class dlist {
	node<T>* head, * tail;
	unsigned int num;

public:
	typedef dlist_iterator<T> iterator;
	typedef dlist_reverse_iterator<T> reverse_iterator;

	//	Constructor:
	//
	dlist();
	dlist(int k, T x);

	//	Size 
	//
	bool empty();
	unsigned size();
	
	//	Iterator:
	//
	reverse_iterator rbegin() {
		return tail;
	}
	reverse_iterator rend() {
		return NULL;
	}
	iterator begin() {
		return head;
	}
	iterator end() {
		return NULL;
	}

	//	Handle list
	//
	void push_back(T x);
	void push_front(T x);
	void pop_back();
	void pop_front();
	void erase(iterator it);

	//	Get properties method, operator:
	//	
	T& front();
	T& back();
	node<T>& getElement(unsigned i);
	node<T>& operator[](unsigned i);


	// Binary Search :
	node<T>* getMidle(node<T>* start, node<T>* last) {
		if (start == NULL)
			return NULL;

		node<T>* slow = start;
		node<T>* fast = start->getnext();
		while (fast != last) {
			fast = fast->getnext();
			
			if (fast != last) {
				slow = slow->getnext();
				fast = fast->getnext();
			}
		}

		return slow;
	}


	node<client>* binarySearch(client value) {
		if (value == head->getelem()) return head;
		if (value == tail->getelem()) return tail;

		node<client>* start = head; // LEFT
		node<client>* last = NULL; // RIGHT
		do {
			// Find Middle
			node<client>* mid = this->getMidle(start, last);

			// Check Middle == NULL ?
			if (mid == NULL) return NULL;

			// Check Value present at middle
			if (mid->getelem().getID() == value.getID())
				return mid;
			else if (value.getID() > mid->getelem().getID()) {
				start = mid->getnext();
			}
			else {
				last = mid->getprev();
			}


		} while (last == NULL ||
			last != start);


		return NULL;
	}

	friend void sort(dlist<client>& List) {
		for (dlist<client>::iterator it1 = List.begin(); it1 != List.end(); it1++) {
			for (dlist<client>::iterator it2 = it1; it2 != List.end(); it2++) {
				if ((*it1).getID() > (*it2).getID()) {
					client temp = (*it1);
					(*it1) = (*it2);
					(*it2) = temp;
				}
			}
		}
	}
};

//
//		Iterator CLASS:
//

template<class T>
dlist_iterator<T>::dlist_iterator<T>(node<T>* c) {
	curr = c;
}

template<class T>
node<T>* dlist_iterator<T>::getcurr() {
	return curr;
}

template<class T>
bool dlist_iterator<T>::operator!=(dlist_iterator<T> it) {
	return curr != it.getcurr();
}

template<class T>
T& dlist_iterator<T>::operator*() {
	return curr->getelem();
}

template<class T>
dlist_iterator<T> dlist_iterator<T>::operator++(int) {
	//curr++
	dlist_iterator<T> it = curr; curr = curr->getnext(); return it;
}

template<class T>
dlist_iterator<T> dlist_iterator<T>::operator++() {
	//++curr
	curr = curr->getnext(); return curr;
}

//
//		Reverse Iterator CLASS:
//

template<class T>
dlist_reverse_iterator<T>::dlist_reverse_iterator<T>(node<T>* c) { curr = c; }

template<class T>
node<T>* dlist_reverse_iterator<T>::getcurr() {
	return curr;
}

template<class T>
dlist_reverse_iterator<T>& dlist_reverse_iterator<T>::operator=(dlist_reverse_iterator<T> it) {
	this->curr = it.getcurr(); return *this;
}
template<class T>
bool dlist_reverse_iterator<T>::operator!=(dlist_reverse_iterator<T> it) {
	return curr != it.getcurr();
}
template<class T>
T& dlist_reverse_iterator<T>::operator*() {
	return curr->getelem();
}
template<class T>
dlist_reverse_iterator<T> dlist_reverse_iterator<T>::operator++(int) {
	//curr++
	dlist_reverse_iterator it = curr; curr = curr->getprev();
	return it;
}
template<class T>
dlist_reverse_iterator<T> dlist_reverse_iterator<T>::operator++() {
	//++curr
	curr = curr->getprev(); return curr;
}


//
//		Double List CLASS:
//


template <class T>
dlist<T>::dlist<T>() { num = 0; head = tail = nullptr; }

//Tao list k phan tu bang x
template <class T>
dlist<T>::dlist<T>(int k, T x) {
	num = 0; head = tail = nullptr;
	while (k--) push_back(x);
}

template <class T>
bool dlist<T>::empty() {
	return num == 0;
}

template <class T>
unsigned dlist<T>::size() {
	return num;
}


template <class T>
void dlist<T>::push_back(T x) {
	if (num == 0) head = tail = new node<T>(x);
	else {
		tail->setnext(new node<T>(x, tail, 0));
		tail = tail->getnext();
	}
	num++;
}
template <class T>
void dlist<T>::push_front(T x) {
	if (num == 0) head = tail = new node<T>(x);
	else {
		head->setprev(new node<T>(x, 0, head));
		head = head->getprev();
	}
	num++;
}
template <class T>
T& dlist<T>::front() {
	return head->getelem();
}

template <class T>
T& dlist<T>::back() {
	return tail->getelem();
}
template <class T>
void dlist<T>::pop_back() {
	if (num == 0) return;
	if (num == 1) head = tail = nullptr;
	else {
		tail = tail->getprev();
		tail->setnext(NULL);
	}
	num--;
}
template <class T>
void dlist<T>::pop_front() {
	if (num == 0) return;
	if (num == 1) head = tail = nullptr;
	else {
		head = head->getnext();
		head->setprev(0);
	}
	num--;
}
template <class T>
void dlist<T>::erase(iterator it) {
	if (it.getcurr() == head) return pop_front();
	if (it.getcurr() == tail) return pop_back();
	node<T>* L = it.getcurr()->getprev(), * R = it.getcurr()->getnext();
	L->setnext(R); R->setprev(L);
	num--;
}

template <class T>
node<T>& dlist<T>::getElement(unsigned i) {
	if (i >= num) {
		return this->back();
	}

	node<T>* h = this->head;
	while (--i > 0) {
		h++;
	}
	return *h;
}
template <class T>
node<T>& dlist<T>::operator[](unsigned i) {
	return getElement(i);
}


#endif // !DBLIST_H_
