#include <iostream>
#include <string>

using namespace std;

struct NgayThang {
    int ngay;
    int thang;
    int nam;
};

/* 1. Lớp NHANSU */
class NHANSU {
protected:
    string hoten;
    string gioitinh;
    NgayThang namsinh;
    string diachi;

public:
    void Nhap() {
        cout << "  - Nhap ho ten: ";
        getline(cin, hoten);
        cout << "  - Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "  - Nhap ngay sinh (ngay thang nam): ";
        cin >> namsinh.ngay >> namsinh.thang >> namsinh.nam;
        cin.ignore();
        cout << "  - Nhap dia chi: ";
        getline(cin, diachi);
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << " | Gioi tinh: " << gioitinh 
             << " | Ngay sinh: " << namsinh.ngay << "/" << namsinh.thang << "/" << namsinh.nam 
             << " | Dia chi: " << diachi << endl;
    }
};

/* 2. Lớp CONGCHUC */
class CONGCHUC : public NHANSU {
private:
    string nganhnghe;
    int namvaoCQ;
    string trinhdo;
    double hsluong;
    double phcap;

public:
    void Nhap() {
        NHANSU::Nhap();
        cout << "  - Nhap nganh nghe: ";
        getline(cin, nganhnghe);
        cout << "  - Nhap nam vao co quan: ";
        cin >> namvaoCQ;
        cin.ignore();
        cout << "  - Nhap trinh do: ";
        getline(cin, trinhdo);
        cout << "  - Nhap he so luong: ";
        cin >> hsluong;
        cout << "  - Nhap phụ cap: ";
        cin >> phcap;
        cin.ignore();
    }

    double thunhap() {
        return hsluong * 830 + phcap;
    }

    void Xuat() {
        NHANSU::Xuat();
        cout << "  -> Nganh nghe: " << nganhnghe << " | Nam vao CQ: " << namvaoCQ 
             << " | Trinh do: " << trinhdo << " | HSL: " << hsluong 
             << " | Phu cap: " << phcap << " | Thu nhap: " << thunhap() << endl;
    }
};

int main() {
    int n;
    do {
        cout << "Nhap so luong cong chuc (n <= 50): ";
        cin >> n;
    } while (n <= 0 || n > 50);
    cin.ignore();

    CONGCHUC ds[50];

    for (int i = 0; i < n; i++) {
        cout << " NHAP THONG TIN CONG CHUC THU " << i + 1;
        ds[i].Nhap();
    }

    cout << "DANH SACH CONG CHUC";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Cong chuc thu " << i + 1 << " ---\n";
        ds[i].Xuat();
    }

    double minTN = ds[0].thunhap();
    for (int i = 1; i < n; i++) {
        if (ds[i].thunhap() < minTN) {
            minTN = ds[i].thunhap();
        }
    }

    cout << "CAC CONG CHUC CO THU NHAP THAP NHAT (" << minTN << ") ";
    for (int i = 0; i < n; i++) {
        if (ds[i].thunhap() == minTN) {
            ds[i].Xuat();
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].thunhap() < ds[j].thunhap()) {
                CONGCHUC temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << " DANH SACH SAU KHI SAP XEP GIAM DAN THEO THU NHAP";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Cong chuc thu " << i + 1 << " ---\n";
        ds[i].Xuat();
    }

    return 0;
}