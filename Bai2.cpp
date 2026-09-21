#include <iostream>
#include <cstring>
using namespace std;

class Date {
private:
    int ngay, thang, nam;

public:
    void nhap() {
        cout << "Nhập ngày: "; cin >> ngay;
        cout << "Nhập tháng: "; cin >> thang;
        cout << "Nhập năm: "; cin >> nam;
    }

    void xuat() {
        cout << ngay << "/" << thang << "/" << nam;
    }
};

class XeHoi {
    private:
    char Hangsanxuat[30];
    Date namSanXuat;
    long giaBan;
    int soLuongBan;
    public:
     void nhap() {
        cout << "Nhập hãng sản xuất: ";
        cin.ignore();
        cin.getline(Hangsanxuat, 30);
        cout << "Nhập năm sản xuất: ";
        namSanXuat.nhap();
        cout << "Nhập giá bán: "; 
        cin >> giaBan;
        cout << "Nhập số lượng bán: "; 
        cin >> soLuongBan;
    }

    void xuat() {
        cout << "Thông tin xe: "<< endl;
        cout << "\nHãng sản xuất: " << Hangsanxuat;
        cout << "\nNăm sản xuất: "; 
        namSanXuat.xuat(); 
        cout << "\nGiá bán: " << giaBan;
        cout << "\nSố lượng bán: " << soLuongBan;
    }
};

int main() {
    XeHoi x;
    cout << "Thông tin xe: " << endl;
    x.nhap();
    x.xuat();
    return 0;
}