#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Tamgiac {
    private: 
    float a,b,c;
public:
    Tamgiac() { a = 0; b = 0; c = 0; }

    void nhap() {
        do {
            cout << "Nhap 3 canh cua tam giac:";
            cout << "/nCanh a: "; cin >> a;
            cout << "Canh b: "; cin >> b;
            cout << "Canh c: "; cin >> c;
            
            if (a + b <= c || a + c <= b || b + c <= a) {
                cout << "/nBa canh khong tao thành tam giac hop le! Vui long nhap lai.";
            }
        } while (a + b <= c || a + c <= b || b + c <= a);
    }

    void xuat() {
        float chuvi = a + b + c;
        float p = chuvi / 2; // Nửa chu vi
        float dientich = sqrt(p * (p - a) * (p - b) * (p - c));
        
        cout << "Chu vi tam giac: " << chuvi << endl;
        cout << "Dien tich tam giac: " << dientich << endl;
    }
};

int main() {
    Tamgiac tg;
    tg.nhap();
    tg.xuat();
    return 0;
}

