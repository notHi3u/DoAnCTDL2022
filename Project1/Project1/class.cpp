#include "class.h"

using namespace std;

string Sach::Ma() {
	return ma;
}
int Sach::TinhTrangSach(int capNhat) {
	if (capNhat != -1) // 0
		tinhTrangSach = capNhat;
	return this->tinhTrangSach;
}
int Sach::KiemTra(string _ma) {
	if (ma.compare(_ma) == 0)
		return 1;
	return 0;
}
void Sach::Nhap() {
	string s;
	char c;
	TextColor(mauTieuDe);
	gotoXY(2 * xx, yy);
	cout << "Nhap thong tin sach:";
	gotoXY(2 * xx, yy + 2);	cout << "Nhap ma: ";
	cin >> ma; // do 5\n
	getline(cin, s);
	gotoXY(2 * xx, yy + 3);		cout << "Nhap ten sach: ";
	getline(cin, tenSach);
	gotoXY(2 * xx, yy + 4);		cout << "Nhap ten tac gia: ";
	getline(cin, tacGia);
	gotoXY(2 * xx, yy + 5);		cout << "Nhap nha xuat ban: ";
	getline(cin, nhaXuatBan);
	gotoXY(2 * xx, yy + 6);		cout << "Nhap gia ban: ";
	cin >> gia;
	gotoXY(2 * xx, yy + 7);		cout << "Nhap nam phat hanh: ";
	cin >> namPhatHanh;
	gotoXY(2 * xx, yy + 8);		cout << "Nhap so trang: ";
	cin >> soTrang;
	gotoXY(2 * xx, yy + 9);		cout << "Nhap ngay nhap kho(dd/mm/yyyy): ";
	cin >> ngayNhapKho.ngay >> c >> ngayNhapKho.thang >> c >> ngayNhapKho.nam;
	tinhTrangSach = 1;
}
int Sach::NhapFile(ifstream& input) {
	string s;
	char c;
	if (!(input >> ma))
		return 0;
	getline(input, s);
	getline(input, tenSach);
	getline(input, tacGia);
	getline(input, nhaXuatBan);
	input >> gia >> namPhatHanh >> soTrang >> ngayNhapKho.ngay >> c >> ngayNhapKho.thang >> c >> ngayNhapKho.nam >> tinhTrangSach;
	return 1;
}
void Sach::XuatFile(ofstream& out) {
	out << ma << endl;
	out << tenSach << endl;
	out << tacGia << endl;
	out << nhaXuatBan << endl;
	out << gia << endl;
	out << namPhatHanh << endl;
	out << soTrang << endl;
	out << ngayNhapKho.ngay << "/" << ngayNhapKho.thang << "/" << ngayNhapKho.nam << endl;
	out << tinhTrangSach << endl;
}
void Sach::Xuat(int x, int y, int color) {
	TextColor(color);
	gotoXY(x, y);
	cout << left << setw(10) << ma << setw(30) << tenSach << setw(20) << tacGia << setw(20) << nhaXuatBan
		<< setw(10) << gia << setw(20) << namPhatHanh << setw(15) << soTrang
		<< setw(2) << right << ngayNhapKho.ngay << "/" << setw(2) << ngayNhapKho.thang << "/" << left << setw(10) << ngayNhapKho.nam
		<< setw(10) << tinhTrangSach << endl;
}

string BanDoc::Ma() {
	return ma;
}
void BanDoc::NhapFile(ifstream& input) {
	char c;
	string enter;
	getline(input, ma);
	getline(input, name);
	input >> ngayDK.ngay >> c >> ngayDK.thang >> c >> ngayDK.nam;
	getline(input, enter);
}

int PhieuMuon::SPM() {
	return soPhieuMuon;
}
string PhieuMuon::MaSach() {
	return maSach;
}
void PhieuMuon::Tao(string _maSach, string _maBanDoc, int _soPhieuMuon) {
	soPhieuMuon = _soPhieuMuon;
	maSach = _maSach;
	maBanDoc = _maBanDoc;
	ngayMuon.layThoiGian();
	ngayTra = ngayMuon;
	ngayTra.ngay += 7;
}
int PhieuMuon::NhapFile(ifstream& in) {
	char c;
	string enter;
	if (!(in >> soPhieuMuon))
		return 0;
	in >> maBanDoc
		>> maSach
		>> ngayMuon.ngay >> c >> ngayMuon.thang >> c >> ngayMuon.nam
		>> ngayTra.ngay >> c >> ngayTra.thang >> c >> ngayTra.nam;
}
void PhieuMuon::HienThi(int x, int y, int color) {
	TextColor(color);
	gotoXY(x, y);
	cout << left << setw(15) << soPhieuMuon << setw(15) << maBanDoc << setw(5) << maSach
		<< setw(2) << right << ngayMuon.ngay << "/" << setw(2) << ngayMuon.thang << "/" << setw(9) << left << ngayMuon.nam
		<< setw(2) << right << ngayTra.ngay << "/" << setw(2) << ngayTra.thang << "/" << setw(9) << left << ngayTra.nam
		<< setw(10) << tinhTrangPhieuMuon << endl;
}
void PhieuMuon::GhiFile(ofstream& out) {
	out << soPhieuMuon << endl;
	out << maBanDoc << endl;
	out << maSach << endl;
	out << ngayMuon.ngay << "/" << ngayMuon.thang << "/" << ngayMuon.nam << endl;
	out << ngayTra.ngay << "/" << ngayTra.thang << "/" << ngayTra.nam << endl;
	out << tinhTrangPhieuMuon << endl;
}

void QuanLySach::KhoiTao() {
	headS = NULL;
	headB = NULL;
	headP = NULL;
}
int QuanLySach::KiemTra(string _ma, int tinhTrang) {
	Sach* i = headS;
	while (i != NULL) {
		if (i->Ma().compare(_ma) == 0) {
			i->TinhTrangSach(tinhTrang);
			return 1;
		}
		i = i->next;
	}
	return 0;
}
void QuanLySach::ThemSach() {
	Sach* p = new Sach;
	p->Nhap();
	p->next = NULL;
	if (this->KiemTra(p->Ma(), -1) == 1) {
		gotoXY(3 * xx, yy + 15);
		cout << "Ma sach da co trong kho vui long kiem tra lai!";
		return;
	}
	Sach* i = headS;
	while (i->next != NULL)
		i = i->next;
	i->next = p;
	gotoXY(3 * xx, yy + 15);
	cout << "Da them vao kho thanh cong!";
	this->XuatFileS();
}
void QuanLySach::DocFileS() {
	Sach* i = nullptr;
	ifstream input;
	input.open("sach.txt");
	while (!input.eof()) {
		Sach* p = new Sach;
		if (!p->NhapFile(input))
			return;
		if (headS == NULL) {
			headS = p;
			i = p;
		}
		else {
			i->next = p;
			i = i->next;
		}
	}
}
void QuanLySach::XuatFileS() {
	ofstream out;
	out.open("sach.txt");
	Sach* i = headS;
	while (i != NULL) {
		i->XuatFile(out);
		i = i->next;
	}
}
void QuanLySach::XuatS() {
	Sach* i = headS;
	int x = 2;
	if (i != NULL) {
		TextColor(mauKhung);
		for (int ii = 0; ii <= 10 + 30 + 20 + 20 + 10 + 20 + 15 + 15 + 10; ii++) {
			gotoXY(xx + ii, yy - 1);		cout << char(196);
			gotoXY(xx + ii, yy + 1);		cout << char(196);
			gotoXY(xx + ii, yy + 3);		cout << char(196);
		}
		TextColor(mauTieuDe);
		gotoXY(4 * xx, yy);		cout << "DANH SACH\n";
		gotoXY(xx, yy + 2);
		cout << left << setw(15) << "Ma" << setw(30) << "Ten sach" << setw(20) << "Tac gia" << setw(20) << "Nha xuat ban"
			<< setw(10) << "Gia" << setw(20) << "Nam phat hanh" << setw(15) << "So trang" << setw(15) << "Ngay nhap"
			<< setw(10) << "Tinh trang\n";
		while (i != NULL) {
			i->Xuat(xx, yy + 2 * x++, mauChu);
			TextColor(mauKhung);
			for (int ii = 0; ii <= 10 + 30 + 20 + 20 + 10 + 20 + 15 + 15 + 10; ii++) {
				gotoXY(xx + ii, yy + 2 * x - 1);		cout << char(196);
			}
			i = i->next;
		}
	}
}
void QuanLySach::XoaS(string _ma) {
	Sach* i = headS;
	gotoXY(2 * xx, yy + 6);
	if (i->Ma().compare(_ma) == 0) {
		if (i->TinhTrangSach(-1) == 1) {
			headS = headS->next;
			cout << "\nDa xoa sach khoi danh sach!";
			return;
		}
		else {
			cout << "\nMa co nguoi muon!";
			return;
		}
	}
	while (i->next != NULL) {
		if (i->next->KiemTra(_ma) == 1) {
			if (i->TinhTrangSach(-1) == 0) {
				i->next = i->next->next;
				cout << "Da xoa sach khoi danh sach!";
				this->XuatFileS();
			}
			else {
				cout << "Khong the xoa vi sach da duoc muon!";
			}
			return; // ket thuc 
		}
		i = i->next;
	}
	cout << "Ma khong co trong danh sach!";
}
int QuanLySach::KiemTraB(string _ma) {
	BanDoc* i = headB;
	while (i != NULL) {
		if (i->Ma() == _ma)
			return 1;
		i = i->next;
	}
	return 0;
}
int QuanLySach::KiemTraTT(string _ma, string _maBanDoc) {
	Sach* i = headS;
	while (i != NULL) {
		if (i->KiemTra(_ma) == 1 && i->TinhTrangSach(-1) == 1 && KiemTraB(_maBanDoc) == 1) {
			i->TinhTrangSach(0);
			return 1;
		}
		i = i->next;
	}
	return 0;
}
void QuanLySach::DocFileB() {
	BanDoc* i = nullptr;
	ifstream input;
	input.open("Bandoc.txt");
	while (!input.eof()) {
		BanDoc* p = new BanDoc;
		p->NhapFile(input);
		p->next = NULL;
		if (headB == NULL) {
			headB = p;
			i = p;
		}
		else {
			i->next = p;
			i = i->next;
		}
	}
}
void QuanLySach::DocFileP() {
	PhieuMuon* i = nullptr;
	ifstream input;
	input.open("PhieuMuon.txt");
	while (!input.eof()) {
		PhieuMuon* p = new PhieuMuon;
		p->NhapFile(input);
		p->next = NULL;
		if (headP == NULL) {
			headP = p;
			i = headP;
		}
		else {
			i->next = p;
			i = i->next;
		}
	}
}
void QuanLySach::ThemPhieuMuon() {
	string _maSach;
	string _maBanDoc;
	gotoXY(2 * xx, yy + 2); cout << "Nhap ma sach: "; cin >> _maSach;
	gotoXY(2 * xx, yy + 4); cout << "Nhap ma ban doc: "; cin >> _maBanDoc;
	if (this->KiemTraTT(_maSach, _maBanDoc) == 1) {
		PhieuMuon* i = headP;
		while (i->next != NULL)
			i = i->next;
		PhieuMuon* p = new PhieuMuon;
		p->Tao(_maSach, _maBanDoc, i->SPM() + 1);
		p->next = NULL;
		i->next = p;
		gotoXY(2 * xx, yy + 6);
		cout << "Them thanh cong";
		i = headP;
		ofstream out;
		out.open("PhieuMuon.txt");
		while (i != NULL) {
			i->GhiFile(out);
			i = i->next;
		}
		this->XuatFileS();
	}
	else {
		gotoXY(2 * xx, yy + 6);
		cout << "Them phieu muon that bai do ma sach khong ton tai hoac ban doc chua dang ky!";
	}
}
void QuanLySach::HienThiPhieu() {
	PhieuMuon* i = headP;
	int x = 2;
	if (i != NULL) {
		TextColor(mauKhung);
		for (int ii = 0; ii <= 15 + 15 + 15 + 15 + 15 + 10; ii++) {
			gotoXY(xx + ii, yy - 1);		cout << char(196);
			gotoXY(xx + ii, yy + 1);		cout << char(196);
			gotoXY(xx + ii, yy + 3);		cout << char(196);
		}
		TextColor(mauTieuDe);
		gotoXY(3 * xx, yy);		cout << "DANH SACH\n";
		gotoXY(xx, yy + 2);
		cout << left << setw(15) << "So phieu" << setw(15) << "Ma ban doc" << setw(15) << "Ma sach" << setw(15) << "Ngay muon" << setw(15) << "Ngay tra"
			<< setw(10) << "Tinh trang\n";
		while (i != NULL) {
			i->HienThi(xx, yy + 2 * x++, mauChu);
			TextColor(mauKhung);
			for (int ii = 0; ii <= 15 + 15 + 15 + 15 + 15 + 10; ii++) {
				gotoXY(xx + ii, yy + 2 * x - 1);		cout << char(196);
			}
			i = i->next;
		}
	}
}
void QuanLySach::XoaPhieu() {
	int _ma;
	gotoXY(2 * xx, yy + 2); cout << "Nhap so phieu muon: ";
	cin >> _ma;
	PhieuMuon* i = headP;
	if (i->SPM() == _ma) {
		this->KiemTra(i->MaSach(), 1);
		headP = headP->next;
		goto Xoa;
	}
	while (i->next != NULL) {
		if (i->next->SPM() == _ma) {
			this->KiemTra(i->next->MaSach(), 1);
			i->next = i->next->next;
			gotoXY(2 * xx, yy + 6);
		Xoa:
			cout << "Xoa thanh cong";
			ofstream out;
			i = headP;
			out.open("PhieuMuon.txt");
			while (i != NULL) {
				i->GhiFile(out);
				i = i->next;
			}
			this->XuatFileS();
			return;
		}
		i = i->next;
	}
	gotoXY(2 * xx, yy + 6);
	cout << "Phieu khong ton tai";
}