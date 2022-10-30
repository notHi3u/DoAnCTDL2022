#include "setup.h"

using namespace std;

class Admin {
private:
	string User;
	string Pass;
public:
	Admin* next;
	void Tao(string _User, string _Pass, Admin* _next);
	int KiemTra(string _User, string _Pass);
	string user();
};

class QuanLyAdmin {
private:
	Admin* headAD;
public:
	void KhoiTao();
	Admin* Add(string _User, string _Pass);
	void Nhap();
	void Xuat();
	int KiemTra(string _User, string _Pass);
};
int DangNhap(QuanLyAdmin quanLy);
