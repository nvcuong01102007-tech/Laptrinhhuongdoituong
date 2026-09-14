#include <iostream>
#include <string>
using namespace std;

class Hocsinh {
    private:
    char hoTen[30];
    char ngaySinh[11];
    char gioiTinh[4];
    float diemTrungBinh;
    char xepLoaiDaoDuc[9];
    public:
    void nhap() {
        cout << "Nhập họ và tên: ";
        cin.getline(hoTen, 30);
        cout << "Ngày, tháng, năm sinh: ";
        cin.getline(ngaySinh, 11);
        cout << "Giới tính: ";
        cin.getline(gioiTinh, 4);
        cout << "Điểm trung bình: "; cin >> diemTrungBinh;
         cin.ignore();
        cout << "Xếp loại đạo đức: ";
        cin.getline(xepLoaiDaoDuc, 9);
    }
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Diem TB: " << diemTrungBinh << endl;
        cout << "Dao duc: " << xepLoaiDaoDuc << endl;
    }
};
int main() {
    Hocsinh hs;
    hs.nhap();
    hs.xuat();
    return 0;
}