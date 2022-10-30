#include "setup.h"
#pragma warning(disable: 4996)
using namespace std;

struct date {
	int ngay;
	int thang;
	int nam;
	void layThoiGian() {
		time_t hientai = time(0);
		tm* t = localtime(&hientai);
		nam = 1900 + t->tm_year;
		thang = 1 + t->tm_mon;
		ngay = t->tm_mday;
	}
};

class Sach {
private:
	string ma;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	int gia;
	int namPhatHanh;
	int soTrang;
	date ngayNhapKho;
	int tinhTrangSach;
public:
	Sach* next;
	string Ma();
	int TinhTrangSach(int capNhat);
	int KiemTra(string _ma);
	void Nhap();
	int NhapFile(ifstream& input);
	void XuatFile(ofstream& out);
	void Xuat(int x, int y, int color);
};
class BanDoc {
private:
	string ma;
	string name;
	date ngayDK;
public:
	BanDoc* next;
	string Ma();
	void NhapFile(ifstream& input);
};
class PhieuMuon {
private:
	int soPhieuMuon;
	string maBanDoc;
	string maSach;
	date ngayMuon;
	date ngayTra;
	int tinhTrangPhieuMuon = 1;
public:
	PhieuMuon* next;
	int SPM();
	string MaSach();
	void Tao(string _maSach, string _maBanDoc, int _soPhieuMuon);
	int NhapFile(ifstream& in);
	void HienThi(int x, int y, int color);
	void GhiFile(ofstream& out);
};
class QuanLySach {
private:
	Sach* headS;
	BanDoc* headB;
	PhieuMuon* headP;
public:
	void KhoiTao();
	int KiemTra(string _ma, int tinhTrang);
	void ThemSach();
	void DocFileS();
	void XuatFileS();
	void XuatS();
	void XoaS(string _ma);
	int KiemTraB(string _ma);
	int KiemTraTT(string _ma, string _maBanDoc);
	void DocFileB();
	void DocFileP();
	void ThemPhieuMuon();
	void HienThiPhieu();
	void XoaPhieu();
};
