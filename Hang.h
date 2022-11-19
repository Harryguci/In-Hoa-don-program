#ifndef HANG_H_
#define HANG_H_
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Hang {
private:
	string name;
	int num;
	int cost;

public:
	Hang() {
		name = "";
		num = cost = 0;
	}

	Hang(string name, int num, int cost) {
		this->name = name;
		this->num = num;
		this->cost = cost;
	}

	void set(string name, int num, int cost) {
		this->name = name;
		this->num = num;
		this->cost = cost;
	}

	string getName() {
		return this->name;
	}

	int getNum() {
		return this->num;
	}

	int getCost() {
		return this->cost;
	}
	void setNum(int newNum) {
		this->num = newNum;
	}
	friend istream& operator>>(istream& is, Hang& A) {
		cout << "\tTen hang: ";
		cin.ignore();
		getline(cin, A.name);
		cout << "\tSo luong: ";
		is >> A.num;
		cout << "\tDon gia: ";
		is >> A.cost;
		return is;
	}

	friend ostream& operator<<(ostream& os, Hang A) {
		os << A.name << setw(20) << A.num << setw(10) << A.cost << endl;
		return os;
	}

	friend bool operator==(Hang A, Hang B) {
		return (A.name == B.name
			&& A.cost == B.cost);
	}

	int CalcCost() {
		return this->num * this->cost;
	}
};
#endif
