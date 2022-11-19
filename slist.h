
#ifndef __slist__cpp__
#define __slist__cpp__
#include "node.h"
#include "slist_iterator.h"

template<class T>
class list {
	node<T>* head, * tail;
	unsigned int num;//so phan tu hien tai trong list -> size
public:
	typedef slist_iterator<T> iterator;
	list() { head = tail = NULL; num = 0; }
	list(int k, T x) {
		head = tail = NULL; num = 0;
		for (int i = 1; i <= k; i++) push_back(x);
	}
	iterator begin() {
		return head;
	}
	iterator end() {
		return NULL;
	}

	unsigned size() { return num; }
	bool empty() { return num == 0; }
	T& front() { return head->getelem(); }
	T& back() { return tail->getelem(); }
	void push_front(T x) {
		head = new node<T>(x, head);
		if (num == 0) tail = head;
		num++;
	}
	void push_back(T x) {
		if (num == 0) push_front(x);
		else {
			tail->setnext(new node<T>(x, NULL));
			tail = tail->getnext();
			num++;
		}
	}
	void pop_front() {
		if (num == 0) return;
		if (num == 1) {
			head = tail = NULL;
		}
		else {
			head = head->getnext();
		}
		num--;
	}
	void pop_back() {
		if (num == 0) return;
		if (num == 1) { head = tail = NULL; num--; return; }
		node<T>* p = head;
		while (p->getnext() != tail) p = p->getnext();
		p->setnext(NULL);
		tail = p;
		num--;
	}
	void erase(iterator it) {
		if (it.getcurr() == head) {
			this->pop_front();
		}
		else if (it.getcurr() == tail) {
			this->pop_back();
		}
		else {
			node<T>* curr = head;
			while (curr->getnext() != it.getcurr()) {
				curr = curr->getnext();
			}
			curr->setnext(it.getcurr()->getnext());
		}
	}
};
#endif
