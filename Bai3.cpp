#include <iostream>
#include <cstring>
using namespace std;

class HangHoa {
    private:
    int maHang;
    char tenHang[50];
    long tienTra;
    public:
    void nhap() {
        cout << "Nhập mã hàng: "; cin >> maHang;
        cin.ignore();
        cout << "Nhập tên hàng: "; cin.getline(tenHang, 50);
        cout << "Nhập số tiền trả: "; cin >> tienTra;
    }

    void xuat() {
        cout << "Mã hàng: " << maHang << " | Tên hàng: " << tenHang << " | Tiền trả: " << tienTra << endl;
    }

    long getTienTra() {
        return tienTra;
    }
};

class PhieuMuaHang{
    private:
    int maPhieu;
    char tenKhach[30];
    int n;
    HangHoa *a;
    public:
    void nhap() {
        cout << "Nhập mã phiếu: "; 
        cin >> maPhieu;
        cin.ignore();
        cout << "Nhập tên khách hàng: "; 
        cin.getline(tenKhach, 30);
        cout << "Nhập số lượng mặt hàng (n): "; 
        cin >> n;
        a = new HangHoa[n];
        for (int i = 0; i < n; i++) {
            cout << " Nhập thông tin mặt hàng thứ " << i + 1 << " ---\n";
            a[i].nhap();
        }
    }
    void xuat() {
        cout << "THÔNG TIN PHIẾU MUA HÀNG ";
        cout << "\nMã phiếu: " << maPhieu;
        cout << "\nTên khách hàng: " << tenKhach;
        cout << "\nDanh sách hàng hóa:\n";
        for (int i = 0; i < n; i++) {
            a[i].xuat();
        }
        cout << "-> Tổng tiền hàng trong phiếu: " << tinhTongTien();
    }

    long tinhTongTien() {
        long tong = 0;
        for (int i = 0; i < n; i++) {
            tong += a[i].getTienTra();
        }
        return tong;
    }
    void suaTenKhach(const char* tenMoi) {
        int i = 0;
    while (tenMoi[i] != '\0' && i < 29) {
        tenKhach[i] = tenMoi[i];
        i++;
    }
    tenKhach[i] = '\0';
    }
};

int main() {
    PhieuMuaHang phieu;
    cout << "Nhập thông tin phiếu mua hàng:\n";
    phieu.nhap();
    cout << "\nHiển thị thông tin ban đầu: ";
    phieu.xuat();
    cout << "\nSau khi sửa tên khách hàng thành 'Le Hoang Anh'";
    phieu.suaTenKhach("Le Hoang Anh");
    phieu.xuat();
    return 0;
}