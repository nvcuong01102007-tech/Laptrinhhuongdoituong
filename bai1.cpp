#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 1. Lớp TacGia */
class TacGia {
private:
    string TenTacGia;
    string DiaChi_TG;

public:
    void Nhap() {
        cout << "  - Nhap ten tac gia: ";
        getline(cin, TenTacGia);
        cout << "  - Nhap dia chi tac gia: ";
        getline(cin, DiaChi_TG);
    }

    void Xuat() {
        cout << "Tac gia: " << TenTacGia << " | Dia chi TG: " << DiaChi_TG << endl;
    }

    string getTenTacGia() { return TenTacGia; }
};

/* 2. Lớp NXB */
class NXB {
private:
    string TenNXB;
    string DiaChi_NXB;

public:
    void Nhap() {
        cout << "  - Nhap ten NXB: ";
        getline(cin, TenNXB);
        cout << "  - Nhap dia chi NXB: ";
        getline(cin, DiaChi_NXB);
    }

    void Xuat() {
        cout << "NXB: " << TenNXB << " | Dia chi NXB: " << DiaChi_NXB << endl;
    }

    string getTenNXB() { return TenNXB; }
};

/* 3. Lớp cơ sở IDSACH */
class IDSACH {
protected:
    string TenSach;
    string MaSach;

public:
    void Nhap() {
        cout << "Nhap ma sach: ";
        getline(cin, MaSach);
        cout << "Nhap ten sach: ";
        getline(cin, TenSach);
    }

    void Xuat() {
        cout << "Ma sach: " << MaSach << " | Ten sach: " << TenSach << endl;
    }

    string getMaSach() { return MaSach; }
};

/* 4. Lớp SACHGK */
class SACHGK : public IDSACH {
private:
    TacGia x;
    NXB y;

public:
    void Nhap() {
        IDSACH::Nhap();
        cout << "[Nhap thong tin Tac gia]\n";
        x.Nhap();
        cout << "[Nhap thong tin NXB]\n";
        y.Nhap();
    }

    void Xuat() {
        IDSACH::Xuat();
        x.Xuat();
        y.Xuat();
    }

    string getTenNXB() { return y.getTenNXB(); }
    string getTenTacGia() { return x.getTenTacGia(); }
};

/* so sánh */
bool soSanhMaSachGiamDan(SACHGK& a, SACHGK& b) {
    return a.getMaSach() > b.getMaSach();
}

int main() {
    int n;
    cout << "Nhap so luong sach giao khoa: ";
    cin >> n;
    cin.ignore();

    vector<SACHGK> ds(n);

    for (int i = 0; i < n; i++) {
        cout << "\n NHAP THONG TIN SACH THU " << i + 1;
        ds[i].Nhap();
    }

    cout << "\n DANH SACH SACH GIAO KHOA";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sach thu " << i + 1 << " ---\n";
        ds[i].Xuat();
    }

    cout << "\n SACH CUA NXB KIMDONG VA TAC GIA Pham Van At";
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].getTenNXB() == "KIMDONG" && ds[i].getTenTacGia() == "Pham Van At") {
            ds[i].Xuat();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sach thoa man dieu kien!\n";
    }

    sort(ds.begin(), ds.end(), soSanhMaSachGiamDan);

    cout << "\n DANH SACH SAU KHI SAP XEP GIAM DAN THEO MA SACH";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sach thu " << i + 1 << " ---\n";
        ds[i].Xuat();
    }

    return 0;
}