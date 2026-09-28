#include<bits/stdc++.h>
using namespace std;

class XeHoi;

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
    friend class XeHoi;
};

class XeHoi {
    private:
    char nhanHieu[30];
    char hangSanXuat[30];
    char kieuDang[30];
    char mauSon[30];
    Date namSanXuat;
    char xuatXu[30];
    double giaBan;
    public: 
    void nhap() {
        cin.ignore();
        cout << "Nhap nhan hieu: "; cin.getline(nhanHieu, 30);
        cout << "Nhap hang san xuat: "; cin.getline(hangSanXuat, 30);
        cout << "Nhap kieu dang: "; cin.getline(kieuDang, 30);
        cout << "Nhap mau son: "; cin.getline(mauSon, 30);
        cout << "Nhap nam san xuat:\n";
        namSanXuat.nhap();
        cin.ignore();
        cout << "Nhap xuat xu: "; cin.getline(xuatXu, 30);
        cout << "Nhap gia ban: "; cin >> giaBan;
    }
    void xuat() {
        cout << "Nhan hieu: " << nhanHieu << " | Hang SX: " << hangSanXuat << endl;
        cout << "  - Kieu dang: " << kieuDang << " | Mau son: " << mauSon << endl;
        cout << "  - Nam SX: "; namSanXuat.xuat(); cout << " | Xuat xu: " << xuatXu << endl;
        cout << "  - Gia ban: " << giaBan << endl;
    }
    string getHangSanXuat() {
        return string(hangSanXuat);
    }
    double getGiaBan() {
        return giaBan;
    }
    int getNamSx() const {
        return namSanXuat.year; 
    }
}; 

int main() {
    int n;
    cout << "Nhap so luong xe hoi: ";
    cin >> n;
    XeHoi *ds = new XeHoi[n];
    
    cout << " Nhap danh sach xe hoi ";
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin xe hoi thu " << i + 1 << ":\n";
        (ds + i)->nhap();
    }

cout << "Danh sach xe hoi vua nhap";
for (int i = 0; i < n; i ++) {
    (ds + i)->xuat();
}

cout << "Xe hoi cua Toyota ";
bool foundToyota = false;
for (int i = 0; i < n; i++) {
    string hang = (ds + i)->getHangSanXuat();
        if (hang == "Toyota" || hang == "toyota" || hang == "TOYOTA") {
            (ds + i)->xuat();
            foundToyota = true;
        }
}
if (!foundToyota) {
        cout << "Khong co xe hoi nao cua hang Toyota.\n";
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ds + i)->getGiaBan() > (ds + j)->getGiaBan()) {
                XeHoi temp = *(ds + i);
                *(ds + i) = *(ds + j);
                *(ds + j) = temp;
            }
        }
    }
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO GIA BAN ===\n";
    for (int i = 0; i < n; i++) {
        (ds + i)->xuat();
    }

    delete[] ds;

    return 0;
}