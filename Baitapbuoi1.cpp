#include <iostream>
using namespace std;
#include <string>

class Dientichhinhthang {
    private:
    int daylon, daynho, chieucao;
    public:
    Dientichhinhthang() {
        daylon = 0;
        daynho = 0;
        chieucao = 0;
    }
    void nhap() {
        cout << "Nhap day lon: ";
        cin >> daylon;
        cout << "Nhap day nho: ";
        cin >> daynho;
        cout << "Nhap chieu cao: ";
        cin >> chieucao;
    }
    void xuat() {
        cout << "Dien tich hinh thang: " << ((daylon+daynho)*chieucao)/2;
    }
};

int main() {
    Dientichhinhthang s1;
    s1.nhap();
    s1.xuat();
    return 0;
}