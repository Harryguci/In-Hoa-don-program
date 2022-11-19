#ifndef CART_H_
#define CART_H_

#include "slist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Hang.h"

class Cart {
private:
	list<Hang> Li;

public:
	int size() {
		return this->Li.size();
	}

	bool Add(Hang value) {
		list<Hang>::iterator it = Li.begin();

		for (it; it != Li.end(); it++) {
			if ((*it) == value) {
				(*it).setNum((*it).getNum() + value.getNum());
				return true;
			}
		}

		Li.push_back(value);
	}

	bool remove(string nameHang, int num) {
		list<Hang>::iterator it = Li.begin();
		for (it; it != Li.end(); it++) {
			if ((*it).getName() == nameHang) {
				(*it).setNum((*it).getNum() - num);
				if ((*it).getNum() <= 0) {
					Li.erase(it);
				}
				return true;
			}
		}
		return false;
	}
	
	int TotalCost() {
		list<Hang>::iterator it = Li.begin();
		int total = 0;
		for (it; it != Li.end(); it++) {
			total += (*it).CalcCost();
		}
		return total;
	}


	bool PrintBill() {
		cout << endl << setw(20) << "HOA DON" << endl;
		cout << "\n\t----------------------------------------------------" << endl;
		list<Hang>::iterator it = Li.begin();
		cout << "\tTen hang|" << setw(20) << "So luong|" << setw(10) << "Don gia|" << endl;
		for (it; it != Li.end(); it++) {
			cout << "\t" << (*it);
		}
		cout << "\t----------------------------------------------------" << endl;
		cout << "\tTong tien: \t" << this->TotalCost();
		
		ofstream outfile;
		outfile.open("hoadon.txt");
		
		outfile << setw(20) << "HOA DON" << endl;
		outfile << "\n----------------------------------------------------" << endl;
		outfile << "Ten hang|" << setw(10) << "So luong|" << setw(10) << "Don gia|" << endl;
		for (it = Li.begin(); it != Li.end(); it++) {
			string nameHang = (*it).getName();
			int num = (*it).getNum();
			int cost = (*it).getCost();

			outfile << nameHang << setw(10) << num << setw(10) << cost << endl;

		}
		outfile << "--------------------------" << endl;
		outfile << "Tong tien: \t" << this->TotalCost();
		outfile.close();

		return true;
	}

};

#endif // !CART_H_
