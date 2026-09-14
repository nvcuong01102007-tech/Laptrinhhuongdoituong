#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class ChuVivaDienTich {
    private: float bankinh;
    public:
    ChuVivaDienTich() {
        bankinh = 0;
    }
    void nhap() {
        cout << "Ban kinh hinh tron la: ";
        cin >> bankinh;
    }
    void xuat() {
        cout << "Chu vi hinh tron la: " << 2*M_PI*bankinh;
        cout << "\nDien tich hinh tron la: " << M_PI*bankinh*bankinh;
    }
};
int main() {
    ChuVivaDienTich s1;
    s1.nhap();
    s1.xuat();
    return 0;
}