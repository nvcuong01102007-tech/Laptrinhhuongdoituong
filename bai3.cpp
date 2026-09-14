#include <iostream>
using namespace std;
#include <string>
#include <math.h>
class Phuongtrinhbacnhat {
    private: 
    float a, b;
    public:
    Phuongtrinhbacnhat() { a = 0; b = 0; }
    void nhap() {
        cout << "Nhap he so a: ";
        cin >> a;
        cout << "Nhap he so b: ";
        cin >> b;
    }
    void xuat() {
        if (a == 0) {
            if (b == 0)
                cout << "Phuong trinh co vo so nghiem." << endl;
            else
                cout << "Phuong trinh vô nghiem." << endl;
        } else {
            cout << "Phuong trinh co nghiem x = " << -b / a << endl;
        }
    }
};
int main () {
    Phuongtrinhbacnhat pt;
    pt.nhap();
    pt.xuat();
    return 0;
}