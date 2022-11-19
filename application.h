#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include <string>
#include "Hang.h"
#include "Cart.h"
using namespace std;

class App {
private:

public:
	App() { ; }
	//
	//	Handle Method:
	//
	void hr() {
		cout << "------------------------------------------------------------------------------------------------------------\n";
	}
	void heading(string text) {
		cout << "\n\n";
		cout << setw(25) << "/ " << text << "\n";
	}
	void PrintMenu() {
		cout << "\n\n";
		cout << "\t\t-----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|             M E N U             | \n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t-----------------------------------\n\n";

		string menulist[] = {
			"1. Them 1 mat hang.",
			"2. Bot so luong 1 mat hang.",
			"3. Tinh tien va In hoa don."
		};

		int len = sizeof(menulist) / sizeof(string);

		for (int i = 0; i < len; i++) {
			cout << "\t\t" << menulist[i] << endl;
		}
	}

	void clrscr() {
		system("cls");
	}

	void AddHang(Cart &cart1) {
		Hang curr;
		cout << "\n\n";
		cin >> curr;
		cart1.Add(curr);
	}

	void SubHang(Cart& cart1) {
		string nameHang;
		int num;
		cout << endl;
		cout << setw(20) << "Nhap ten mat hang muon bot: ";
		cin.ignore();
		getline(cin, nameHang);
		cout << setw(20) << "Nhap so luong muon bot: ";
		cin >> num;
		cart1.remove(nameHang, num);
	}

	void PrintBill(Cart& cart1) {
		cart1.PrintBill();
	}
};


#endif // !APPLICATION_H_
