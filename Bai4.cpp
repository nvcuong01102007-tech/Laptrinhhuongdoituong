#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

class HangHoa {
    private:
    char maHang[20];
    char tenHang[30];
    long donGia;
    int soLuong;

public:
    void nhap() {
        cout << "Nhập mã hàng: ";
        cin.getline(maHang, 20) ;
        cin.ignore();
        cout << "Nhập tên hàng: ";
        cin.getline(tenHang, 30);
        cout << "Nhập đơn giá: ";
        cin >> donGia;
        cout << "Nhập số lượng: ";
        cin >> soLuong;
    }
    void xuat () {
        cout << left << setw(10) << maHang 
             << setw(20) << tenHang 
             << setw(12) << donGia 
             << setw(10) << soLuong 
             << setw(12) << getThanhTien() << endl;
    }
    double getThanhTien() {
        return donGia * soLuong;
    }
    int getSoLuong() {
        return soLuong; }
        string getTenHang() {
        return tenHang;
    }

    void setSoLuong(int slMoi) {
        soLuong = slMoi;
    }
};
class Phieu {
private:
    string maPhieu;
    string ngayLap;
    string maNV;
    string tenNV;
    string tenKhachHang;
    int n;
    HangHoa *dsHang; 
public:
    void nhap() {
        cout << "Nhập mã phiếu: "; 
        cin >> maPhieu;
        cout << "Nhập ngày lập phiếu: "; 
        cin >> ngayLap;
        cout << "Nhập mã người lập phiếu: "; 
        cin >> maNV;
        cin.ignore();
        cout << "Nhập họ tên người lập phiếu: "; 
        getline(cin, tenNV);
        cout << "Nhập tên khách hàng: "; 
        getline(cin, tenKhachHang);
        cout << "Nhập số lượng loại hàng hóa (n): "; 
        cin >> n;
        dsHang = new HangHoa[n];
        for (int i = 0; i < n; i++) {
            cout << "\nNhập hàng hóa thứ " << i + 1;
            dsHang[i].nhap();
        }
    }

    void xuat() {
        cout << "Bách hóa Sơn Tùng\n";
        cout << "PHIẾU MUA HÀNG\n";
        cout << "Mã phiếu: " << maPhieu << "Ngày lập phiếu: " << ngayLap << endl;
        cout << "Mã người lập: " << maNV << "Họ tên người lập: " << tenNV << endl;
        cout << "Khách hàng: " << tenKhachHang << endl;
        cout << left << setw(10) << "Mã hàng" 
             << setw(20) << "Tên hàng" 
             << setw(12) << "Đơn giá" 
             << setw(10) << "Số lượng" 
             << setw(12) << "Thành tiền" << endl;
        
        double tongTien = 0;
        int tongSoLuong = 0;
        for (int i = 0; i < n; i++) {
            dsHang[i].xuat();
            tongTien += dsHang[i].getThanhTien();
            tongSoLuong += dsHang[i].getSoLuong();
        }
        cout << left << setw(42) << "TỔNG" 
             << setw(10) << tongSoLuong 
             << setw(12) << tongTien << endl;
    }

    void demSoLuongLonHon15() const {
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (dsHang[i].getSoLuong() > 15) {
                dem++;
            }
        }
        cout << "-> Có " << dem << " mặt hàng có số lượng > 15.\n";
    }

    void thongKeSoLuongMax() const {
        if (n <= 0) return;
        int maxSl = dsHang[0].getSoLuong();
        for (int i = 1; i < n; i++) {
            if (dsHang[i].getSoLuong() > maxSl) {
                maxSl = dsHang[i].getSoLuong();
            }
        }

        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (dsHang[i].getSoLuong() == maxSl) {
                dem++;
            }
        }
        cout << "-> Có " << dem << " mặt hàng có số lượng mua lớn nhất (Số lượng = " << maxSl << ").\n";
    }

    void sapXepGiamDanTheoSoLuong() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dsHang[i].getSoLuong() < dsHang[j].getSoLuong()) {
                    swap(dsHang[i], dsHang[j]);
                }
            }
        }
    }

    void suaKhachHang(string tenMoi) {
        tenKhachHang = tenMoi;
    }

    void suaSoLuongBimBim() {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (dsHang[i].getTenHang() == "Bim bim" || dsHang[i].getTenHang() == "Bim Bim") {
                dsHang[i].setSoLuong(120);
                found = true;
            }
        }
        if (found) {
            cout << "-> Đã cập nhật số lượng hàng 'Bim bim' thành 120.\n";
        } else {
            cout << "-> Không tìm thấy mặt hàng 'Bim bim' trong phiếu.\n";
        }
    }

    // Destructor giải phóng bộ nhớ
    ~Phieu() {
        delete[] dsHang;
    }
};

int main() {
    Phieu p;    
    cout << "NHẬP THÔNG TIN PHIẾU MUA HÀNG:\n";
    p.nhap();   
    cout << " IN PHIẾU BAN ĐẦU ";
    p.xuat();
    cout << "\n1 :\n";
    p.demSoLuongLonHon15();
    cout << "\n2 :\n";
    p.thongKeSoLuongMax();
    cout << "\n3 : Sắp xếp giảm dần theo số lượng\n";
    p.sapXepGiamDanTheoSoLuong();
    p.xuat();
    cout << "\n4 : Sửa tên khách hàng thành 'Le Van Hoang'\n";
    p.suaKhachHang("Le Van Hoang");
    p.xuat();
    cout << "\n5 : Sửa số lượng 'Bim bim' thành 120\n";
    p.suaSoLuongBimBim();
    p.xuat();
    return 0;
}