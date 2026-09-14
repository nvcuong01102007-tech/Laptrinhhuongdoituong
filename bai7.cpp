#include <iostream>
#include <string>
using namespace std;

class CanBo {
    private:
    char MaCanBo[30];
    char HovaTen[30];
    char ngaySinh[11];
    int soNgayLamViecTrongThang;
    public:
    void nhap() {
        cout << "Nhập họ và tên: ";
        cin.getline(HovaTen, 30);
        cout << "Ngày, tháng, năm sinh: ";
        cin.getline(ngaySinh, 11);
        cout << "Mã cán bộ: ";
        cin.getline(MaCanBo, 30);
        cout << "Số ngày làm việc trong tháng: ";
        cin >> soNgayLamViecTrongThang;
        cin.ignore();
    }
    long tinhLuong() {
        return (long)soNgayLamViecTrongThang * 250000;
    }
    void xuat() {
        cout << "\n--- Thong tin can bo ---\n";
        cout << "Ma can bo: " << MaCanBo << endl;
        cout << "Ho ten: " << HovaTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "So ngay lam viec: " << soNgayLamViecTrongThang << endl;
        cout << "Tong luong: " << tinhLuong() << " VND" << endl; }
};
int main() {
    CanBo cb;
    cb.nhap();
    cb.xuat();
    return 0;
}