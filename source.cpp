#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "application.h"
#include "Hang.h"
#include "Cart.h"

using namespace std;

int main()
{
	bool is_quit = false; // Kiem tra dieu kien thoat vong lap
	Cart cart1;
	App app; // Application
	int status = 0;

	// 1. Add 1 mat hang
	// 2. Bot 1 mat hang
	// 3. Tinh tien va In hoa don

	while (!is_quit) {
		Sleep(200);
		app.clrscr(); // Xoa man hinh

		app.heading("HOA DON BAN HANG"); // Title of the program

		app.PrintMenu(); // In menu len man hinh

		cout << "\n\t\t   Nhap lua chon: ";

		cin >> status; // User Nhap lua chon

		//
		// Xu ly lua chon
		//
		switch (status)
		{
		case 1: // Them 1 mat hang
			app.AddHang(cart1);
			break;
		case 2: // Bot 1 mat hang
			app.SubHang(cart1);
			break;
		case 3: // Tinh tien va In hoa don
			app.PrintBill(cart1);
			break;
		
		default:
			cout << "\n\tBan da nhap sai dinh dang!\n";
			break;
		}

		char temp;
		cout << "\n\n" << setw(50) << "---------------------------------\n";
		cout << setw(50) << "Ban co muon tiep tuc ? (Y / N) : ";
		do {
			cin >> temp;
		} while (temp != 'Y' && temp != 'N');


		if (temp == 'N') {
			is_quit = true;
			app.clrscr();

			for (int i = 3; i >= 0; i--) {
				Sleep(1000);
				app.clrscr();
				cout << "\n\n\n\n\n" << setw(47) << "CHUONG TRINH SE DONG SAU " << i << "s\n";
			}
		}
	}

	//system("pause");

	return 0;
}

