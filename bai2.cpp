#include <iostream>
#include <string>

using namespace std;

/*  1. Lớp HANG */
class HANG {
protected:
    string MaHang;
    string TenHang;
    double Gia;

public:
    void Nhap() {
        cout << "  - Nhap ma hang: ";
        getline(cin, MaHang);
        cout << "  - Nhap ten hang: ";
        getline(cin, TenHang);
        cout << "  - Nhap gia: ";
        cin >> Gia;
        cin.ignore();
    }

    void Xuat() {
        cout << "Ma hang: " << MaHang << " | Ten hang: " << TenHang << " | Gia: " << Gia << endl;
    }
};

/* 2. Lớp HANG_MM */
class HANG_MM : public HANG {
private:
    string ChatLieu;
    string KieuDang;
    int SoLuong;

public:
    void Nhap() {
        HANG::Nhap();
        cout << "  - Nhap chat lieu: ";
        getline(cin, ChatLieu);
        cout << "  - Nhap kieu dang: ";
        getline(cin, KieuDang);
        cout << "  - Nhap so luong: ";
        cin >> SoLuong;
        cin.ignore();
    }

    void Xuat() {
        HANG::Xuat();
        cout << "  -> Chat lieu: " << ChatLieu << " | Kieu dang: " << KieuDang << " | So luong: " << SoLuong << endl;
    }

    int getSoLuong() { return SoLuong; }
};

/* 3. Lớp CUAHANG */
class CUAHANG {
private:
    string MaCH;
    string TenCH;
    HANG_MM* x;
    int n;

public:
    CUAHANG() {
        x = NULL;
        n = 0;
    }

    ~CUAHANG() {
        if (x != NULL) {
            delete[] x;
        }
    }

    void Nhap() {
        cout << "Nhap ma cua hang: ";
        getline(cin, MaCH);
        cout << "Nhap ten cua hang: ";
        getline(cin, TenCH);
        cout << "Nhap so luong mat hang (n): ";
        cin >> n;
        cin.ignore();

        x = new HANG_MM[n];
        for (int i = 0; i < n; i++) {
            cout << "\n[Nhap mat hang thu " << i + 1 << "]\n";
            x[i].Nhap();
        }
    }

    void Xuat() {
        cout << "THONG TIN CUA HANG";
        cout << "Ma cua hang: " << MaCH << endl;
        cout << "Ten cua hang: " << TenCH << endl;
        cout << "--- Danh sach cac mat hang ---\n";
        for (int i = 0; i < n; i++) {
            cout << "Mat hang " << i + 1 << ":\n";
            x[i].Xuat();
        }
    }

    void doiTenCuaHang(string tenMoi) {
        TenCH = tenMoi;
    }

    void xuatHangSoLuongLon() {
        cout << "CAC MAT HANG CO SO LUONG > 25";
        bool coHang = false;
        for (int i = 0; i < n; i++) {
            if (x[i].getSoLuong() > 25) {
                x[i].Xuat();
                coHang = true;
            }
        }
        if (!coHang) {
            cout << "Khong co mat hang nao co so luong > 25.\n";
        }
    }
};

int main() {
    CUAHANG ch;
    ch.Nhap();
    ch.Xuat();

    ch.doiTenCuaHang("IVYMODA");

    cout << "\n>>> Sau khi doi ten cua hang thanh IVYMODA <<<\n";
    ch.Xuat();

    ch.xuatHangSoLuongLon();

    return 0;
}