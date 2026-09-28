#include<bits/stdc++.h>
using namespace std;

class DoanhNghiep;

class Date {
    private: 
    int day;
    int month;
    int year;
    public: 
    void nhap() {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    }
    void xuat() {
        cout << day << "/" << month << "/" << year;
    }
    friend class DoanhNghiep;
};

class DiaChi {
    private: 
    char dienThoai[12];
    char phuong[30];
    char quan[30];
    char thanhPho[30];
    public: 
    void nhap() {
        cin.ignore(); // Xóa bộ nhớ đệm
        cout << "Nhap dien thoai: "; cin.getline(dienThoai, 12);
        cout << "Nhap phuong: "; cin.getline(phuong, 30);
        cout << "Nhap quan: "; cin.getline(quan, 30);
        cout << "Nhap thanh pho: "; cin.getline(thanhPho, 30);
    }

    void xuat() const {
        cout << "SDT: " << dienThoai << ", P. " << phuong 
             << ", Q. " << quan << ", TP. " << thanhPho;
    }

    string getThanhPho() const {
        return string(thanhPho);
    }
};

class DoanhNghiep {
    private: 
    int maDn;
    char tenDn[60];
    Date ngayTl;
    DiaChi diaChi;
    char giamDoc[30];
    long doanhThu;
    public:
    void nhap() {
        cout << "Nhap ma doanh nghiep: "; cin >> maDn;
        cin.ignore();
        cout << "Nhap ten doanh nghiep: "; cin.getline(tenDn, 60);
        cout << "Nhap ngay thanh lap:\n";
        ngayTl.nhap();
        cout << "Nhap dia chi:\n";
        diaChi.nhap();
        cout << "Nhap ten giam doc: "; cin.getline(giamDoc, 30);
        cout << "Nhap doanh thu: "; cin >> doanhThu;
    }
    void xuat() {
        cout << "Ma DN: " << maDn << " | Ten DN: " << tenDn << endl;
        cout << "  - Ngay thanh lap: "; ngayTl.xuat(); cout << endl;
        cout << "  - Dia chi: "; diaChi.xuat(); cout << endl;
        cout << "  - Giam doc: " << giamDoc << " | Doanh thu: " << doanhThu << endl;
    }
    int getMaDn() {
        return maDn;
    }
    string getThanhPho() {
        return diaChi.getThanhPho();
    }

    int getNamTl() {
        return ngayTl.year;
    }

    long getDoanhThu() const {
        return doanhThu;
    }

    void suaThongTin() {
        cout << "--- Nhap lai thong tin moi cho doanh nghiep --- \n";
        cin.ignore();
        cout << "Nhap ten doanh nghiep moi: "; cin.getline(tenDn, 60);
        cout << "Nhap ngay thanh lap moi:\n";
        ngayTl.nhap();
        cout << "Nhap dia chi moi:\n";
        diaChi.nhap();
        cout << "Nhap ten giam doc moi: "; cin.getline(giamDoc, 30);
        cout << "Nhap doanh thu moi: "; cin >> doanhThu;
    }
};

int main() {
    int n;
    DoanhNghiep ds[20];

    do {
        cout << "Nhap so luong doanh nghiep (0 < n < 20): ";
        cin >> n;
        if (n <= 0 || n >= 20) {
            cout << "So luong khong hop le. Vui long nhap lai!\n";
        }
    } while (n <= 0 || n >= 20);

    cout << "\n=== NHAP DANH SACH DOANH NGHIEP ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin doanh nghiep thu " << i + 1 << ":\n";
        ds[i].nhap();
    }
    cout << "\n=== DANH SACH DOANH NGHIEP VUA NHAP ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }

    cout << "\n=== CAC DOANH NGHIEP O HA NOI ===\n";
    bool foundHN = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].getThanhPho().find("Ha Noi") != string::npos || 
            ds[i].getThanhPho().find("Hà Nội") != string::npos) {
            ds[i].xuat();
            foundHN = true;
        }
    }
    if (!foundHN) {
        cout << "Khong co doanh nghiep nao o Ha Noi.\n";
    }

    long tongDoanhThu2015 = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].getNamTl() == 2015) {
            tongDoanhThu2015 += ds[i].getDoanhThu();
        }
    }
    cout << "\nTong doanh thu cua cac doanh nghiep thanh lap nam 2015 la: " << tongDoanhThu2015 << endl;

    int maTimKiem;
    cout << "\n=== SUA THONG TIN DOANH NGHIEP ===\n";
    cout << "Nhap ma doanh nghiep can sua: ";
    cin >> maTimKiem;

    bool foundId = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].getMaDn() == maTimKiem) {
            cout << "Tim thay doanh nghiep! Tien hanh cap nhat lai thong tin:\n";
            ds[i].suaThongTin();
            foundId = true;
            break;
        }
    }

    if (!foundId) {
        cout << "Khong tim thay doanh nghiep co ma " << maTimKiem << ".\n";
    } else {
        cout << "\n=== DANH SACH SAU KHI SUA ===\n";
        for (int i = 0; i < n; i++) {
            ds[i].xuat();
        }
    }

    return 0;
}