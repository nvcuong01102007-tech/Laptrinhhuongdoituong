#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Phuongtrinhbac2 {
    private:
    float a, b, c;
    public: 
    Phuongtrinhbac2 () { a = 0; b = 0; c = 0; }
    void nhap() {
        cout << "Nhap a: "; cin >> a;
        cout << "Nhap b: "; cin >> b;
        cout << "Nhap c: "; cin >> c;
    }
void xuat() {
        if (a == 0) {
            // Quay về bậc nhất: bx + c = 0
            if (b == 0) {
                if (c == 0) cout << "Phuong trinh co vo so nghiem.\n";
                else cout << "Phuong trinh vo nghiem.\n";
            } else {
                cout << "Phuong trinh co 1 nghiem x = " << -c / b << "\n";
            }
            return;
        }
        
        float delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem.\n";
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << "\n";
        } else {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2 << "\n";
        }
}
};

int main () {
    Phuongtrinhbac2 pt2;
    pt2.nhap();
    pt2.xuat();
    return 0;
}