#include "classAdmin.h"
#pragma warning(disable: 4996)
void Admin::Tao(string _User, string _Pass, Admin* _next) {
	User = _User;
	Pass = _Pass;
	next = _next;
}
int Admin::KiemTra(string _User, string _Pass) {
	if (User == _User && Pass == _Pass)
		return 1;
	return 0;
}
string Admin::user() {
	return User;
}

void QuanLyAdmin::KhoiTao() {
	headAD = NULL;
}
Admin* QuanLyAdmin::Add(string _User, string _Pass) {
	Admin* p = new Admin;
	p->Tao(_User, _Pass, headAD);
	return p;
}
void QuanLyAdmin::Nhap() {
	ifstream input;
	input.open("admin.txt");
	int n;
	input >> n;
	string _User, _Pass;
	while (n > 0) {
		input >> _User >> _Pass;
		headAD = this->Add(_User, _Pass);
		n--;
	}
}
void QuanLyAdmin::Xuat() {
	Admin* i = headAD;
	while (i != NULL) {
		cout << i->user() << endl;
		i = i->next;
	}
}
int QuanLyAdmin::KiemTra(string _User, string _Pass) {
	Admin* i = headAD;
	while (i != NULL) {
		if (i->KiemTra(_User, _Pass) == 1) {
			return 1;
		}
		i = i->next;
	}
	return 0;
}

int DangNhap(QuanLyAdmin quanLy) {
	int num = 3; 	// so lan dang nhap
	int x = 2; 		// toa do hang bat dau cua khung
	int y = 25;		// toa do cot bat dau cua khung
	int m = 50; 	// do rong cua khung
	int n = 10; 	//
	Khung(y, x, m, n);
	Khung(y, x, m, n - 8);
	TextColor(10);
	gotoXY(y + m / 2 - 5, x + 1); cout << "DANG NHAP";
	gotoXY(y + 5, x + 3); cout << "User: ";
	gotoXY(y + 5, x + 6); cout << "Password: ";
	while (num > 0) {
		TextColor(7);
		string tk, mk;
		char c;			// ki tu de lay mat khau
		gotoXY(y + 5, x + 4);	cin >> tk;
		gotoXY(y + 5 + mk.size(), x + 7);
		while (1) {
			if (kbhit()) {
				c = _getch();
				switch (c) {
				case 13: {
					goto Out;
					break;
				}
				case 8: {
					if (mk.size() > 0) {
						gotoXY(y + 5 + mk.size(), x + 7);
						mk.erase(mk.size() - 1, 1);
						cout << " ";
					}
					break;
				}
				default: {
					mk.push_back(c);
					gotoXY(y + 5 + mk.size(), x + 7);
					cout << "*";
					break;
				}
				}
			}
		}
	Out:
		if (quanLy.KiemTra(tk, mk) == 0) {
			TextColor(4);
			gotoXY(y - 3, x + n + 3);
			cout << "Tai khoan hoac mat khau khong chinh xac! Vui long kiem tra lai.";
			Sleep(1000);	// dung chuong trinh 1s
			gotoXY(y - 3, x + n + 3);
			cout << "                                                               "; //  Xoa dong thong bao
			for (int i = 1; i < m; i++) {
				gotoXY(y + i, x + 4); cout << " ";
				gotoXY(y + i, x + 7); cout << " ";
			}
			num--;
		}
		else {
			system("cls");
			return 1;	// dang nhap thanh cong
		}
	}
	system("cls");
	return 0;	// dang nhap that bai
}
