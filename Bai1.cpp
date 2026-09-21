#include <iostream>
using namespace std;
#include <cstring>

class NSX {
    private:
    char maNSX[30];
    char tenNSX[30];
    char dcNSX[30];
    public:
    void nhap() {
        cout << "Nhập mã NSX: ";
        cin >> maNSX;
        cin.ignore(); 
        cout << "Nhập tên NSX: ";
        cin.getline(tenNSX, 30);
        cout << "Nhập địa chỉ NSX: ";
        cin.getline(dcNSX, 30);
    }
    void xuat() {
        cout << "Mã NSX: " << maNSX;
        cout << "\nTên NSX: " << tenNSX;
        cout << "\nĐịa chỉ NSX: " << dcNSX;
    }
};

class Hang {
private:
    char maHang[30];
    char tenHang[30];
    double donGia;
    double trongLuong;
    NSX x;

public:
    void nhap() {
        cout << "Nhập mã hàng: ";
        cin >> maHang;
        cin.ignore();
        cout << "Nhập tên hàng: ";
        cin.getline(tenHang, 30);
        cout << "Nhập đơn giá: ";
        cin >> donGia;
        cout << "Nhập trọng lượng: ";
        cin >> trongLuong;
        cout << "Nhập thông tin nhà sản xuất";
        x.nhap();
    }

    void xuat() {
        cout << " THÔNG TIN MẶT HÀNG ";
        cout << "\nMã hàng: " << maHang;
        cout << "\nTên hàng: " << tenHang;
        cout << "\nĐơn giá: " << donGia;
        cout << "\nTrọng lượng: " << trongLuong;
        cout << "\nThông tin nhà sản xuất";
        x.xuat();
    }
};

int main() {
  Hang hang1;
    cout << "NHẬP THÔNG TIN MẶT HÀNG:\n";
    hang1.nhap();
    hang1.xuat();
    return 0;
}
