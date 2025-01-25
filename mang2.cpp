#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Khai báo struct SinhVien
struct SinhVien {
    string maSo;
    string hoTen;
    string ngaySinh;
    float diemTB;
};

// Hàm thêm sinh viên mới vào danh sách
void themSinhVien(SinhVien ds[], int &soLuong, int maxSinhVien) {
    if (soLuong >= maxSinhVien) {
        cout << "Danh sách đã đầy. Không thể thêm sinh viên mới.\n";
        return;
    }

    SinhVien sv;
    cout << "Nhập mã số sinh viên: ";
    cin >> sv.maSo;
    cin.ignore();
    cout << "Nhập họ tên sinh viên: ";
    getline(cin, sv.hoTen);
    cout << "Nhập ngày sinh (dd/mm/yyyy): ";
    cin >> sv.ngaySinh;
    cout << "Nhập điểm trung bình: ";
    cin >> sv.diemTB;

    ds[soLuong++] = sv;
    cout << "Thêm sinh viên thành công!\n";
}

// Hàm hiển thị danh sách sinh viên
void hienThiDanhSach(SinhVien ds[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sách trống. Không có sinh viên nào để hiển thị.\n";
        return;
    }

    cout << left << setw(15) << "Mã số"
         << setw(25) << "Họ tên"
         << setw(15) << "Ngày sinh"
         << setw(10) << "Điểm TB" << endl;
    cout << string(65, '-') << endl;

    for (int i = 0; i < soLuong; ++i) {
        cout << left << setw(15) << ds[i].maSo
             << setw(25) << ds[i].hoTen
             << setw(15) << ds[i].ngaySinh
             << setw(10) << fixed << setprecision(2) << ds[i].diemTB << endl;
    }
}

// Hàm tìm kiếm sinh viên theo mã số
void timKiemSinhVien(SinhVien ds[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sách trống. Không có sinh viên nào để tìm kiếm.\n";
        return;
    }

    string maSo;
    cout << "Nhập mã số sinh viên cần tìm: ";
    cin >> maSo;

    for (int i = 0; i < soLuong; ++i) {
        if (ds[i].maSo == maSo) {
            cout << "Tìm thấy sinh viên:\n";
            cout << "Mã số: " << ds[i].maSo
                 << ", Họ tên: " << ds[i].hoTen
                 << ", Ngày sinh: " << ds[i].ngaySinh
                 << ", Điểm TB: " << ds[i].diemTB << endl;
            return;
        }
    }
    cout << "Không tìm thấy sinh viên với mã số " << maSo << ".\n";
}

// Hàm hiển thị sinh viên có điểm TB cao nhất
void hienThiDiemTB_CaoNhat(SinhVien ds[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sách trống. Không có sinh viên nào.\n";
        return;
    }

    int viTriCaoNhat = 0;
    for (int i = 1; i < soLuong; ++i) {
        if (ds[i].diemTB > ds[viTriCaoNhat].diemTB) {
            viTriCaoNhat = i;
        }
    }

    cout << "Sinh viên có điểm TB cao nhất:\n";
    cout << "Mã số: " << ds[viTriCaoNhat].maSo
         << ", Họ tên: " << ds[viTriCaoNhat].hoTen
         << ", Ngày sinh: " << ds[viTriCaoNhat].ngaySinh
         << ", Điểm TB: " << ds[viTriCaoNhat].diemTB << endl;
}

// Hàm hiển thị sinh viên có điểm TB thấp nhất
void hienThiDiemTB_ThapNhat(SinhVien ds[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sách trống. Không có sinh viên nào.\n";
        return;
    }

    int viTriThapNhat = 0;
    for (int i = 1; i < soLuong; ++i) {
        if (ds[i].diemTB < ds[viTriThapNhat].diemTB) {
            viTriThapNhat = i;
        }
    }

    cout << "Sinh viên có điểm TB thấp nhất:\n";
    cout << "Mã số: " << ds[viTriThapNhat].maSo
         << ", Họ tên: " << ds[viTriThapNhat].hoTen
         << ", Ngày sinh: " << ds[viTriThapNhat].ngaySinh
         << ", Điểm TB: " << ds[viTriThapNhat].diemTB << endl;
}

// Hàm main
int main() {
    const int maxSinhVien = 100;
    SinhVien ds[maxSinhVien];
    int soLuong = 0;
    int luaChon;

    do {
        cout << "\n--- Quản lý thông tin sinh viên ---\n";
        cout << "1. Thêm sinh viên\n";
        cout << "2. Hiển thị danh sách sinh viên\n";
        cout << "3. Tìm kiếm sinh viên theo mã số\n";
        cout << "4. Hiển thị sinh viên có điểm TB cao nhất\n";
        cout << "5. Hiển thị sinh viên có điểm TB thấp nhất\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                themSinhVien(ds, soLuong, maxSinhVien);
                break;
            case 2:
                hienThiDanhSach(ds, soLuong);
                break;
            case 3:
                timKiemSinhVien(ds, soLuong);
                break;
            case 4:
                hienThiDiemTB_CaoNhat(ds, soLuong);
                break;
            case 5:
                hienThiDiemTB_ThapNhat(ds, soLuong);
                break;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng thử lại.\n";
        }
    } while (luaChon != 0);

    return 0;
}
