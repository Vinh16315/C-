#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <limits>
using namespace std;

class SinhVien 
{
public:
    string id;
    string hoTen;
    string ngaySinh;
    double gpa;
    SinhVien*prev;  // tro vao node truoc
    SinhVien*next;  // tro vao node tiep theo

SinhVien( string _id, string _hoTen , string _ngaySinh , double _gpa)
    {
        id = _id;
        hoTen = _hoTen;
        ngaySinh = _ngaySinh;
        gpa = _gpa;
        prev = nullptr; // con tro rong
        next = nullptr; // con tro rong
    }
};

class Danhsachsinhvien
{
    private:
    SinhVien* head; // tro den sv dau tien
    SinhVien* tail; //tro den sinh vien cuoi cung

    public:
    Danhsachsinhvien(): head(nullptr) , tail(nullptr) {}

//Ham ktra validation: 
bool ktraID(const string& id){
    if (id.length() != 8 ) return false; // do dai mssv phai = 8
    for (char c: id) {
        if(!isdigit(c)) return false; // ky tu phai la so
    }
    return true;
}
bool ktraNgaySinh(const string& ngaySinh){
    regex pattern("^\\d{2}/\\d{2}/\\d{4}$");  // cai nay de kiem tra dinh dang dd/mm/yyy
    if (!regex_match(ngaySinh, pattern)) {   
        return false;
    }
    int ngay, thang ,nam;
    sscanf(ngaySinh.c_str(), "%d/%d/%d", &ngay, &thang, &nam);

    if (nam < 1900 || nam > 2100) return false;
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > 31) return false;
    return true;
}
bool ktraGPA(double& gpa) {
    return gpa >= 0 && gpa <= 4; // chi tra ve kqua neu 4>=gpa>=0
}

void themsinhvien(string _id, string _hoTen, string _ngaySinh, double _gpa )
{
    while (!ktraID(_id)) {
            cout << "Ma so sinh vien phai bao gom 8 ki tu so, vui long nhap lai: ";
            cin >> _id;
        }

    while (!ktraNgaySinh(_ngaySinh)) {
            cout << "Dinh dang ngay sinh phai la dd/mm/yyyy , vui long nhap dung dinh dang:";
            cin >> _ngaySinh;
        }

    while (!ktraGPA(_gpa)) {
            cout << "Diem trung binh (tren thang diem 4) la so thuc nam trong khoang 0.0 đến 4.0.\n";
            cout << "Nhap lai diem trung binh: ";
            cin >> _gpa;
        }
    SinhVien* newSinhVien = new SinhVien(_id,_hoTen,_ngaySinh,_gpa);
    if (!head) {  // neu danh sach chua co sinh vien nao thi sv moi se la head va tail luon
        head = tail = newSinhVien;
    }
    else {
        tail->next = newSinhVien; // sinh vien moi se la "next" cua sinh vien cuoi cung
        newSinhVien->prev = tail; // sinh vien "prev" cua sinh vien moi la sinh vien cuoi cung
        tail = newSinhVien; // sinh vien moi them vao` se tro thanh sinh vien cuoi cung 
    }
    cout <<"Them sinh vien moi thanh cong!" << endl; 
}



void hienthisinhvien()
{
if (!head){
    cout <<"Danh sach sinh vien hien dang trong\n";
    return;
} 
    SinhVien* current = head; // tao con tro current de duyet qua lan luot tung sinh vien, bat dau tu sinh vien dau tien "HEAD"
    while (current) {
        cout << "ID: [" << current ->id <<"], " << "Ho va ten: [" << current->hoTen <<"], " <<"Ngay sinh: [" << current->ngaySinh <<"], " <<"GPA: [" <<current->gpa <<"]\n";
        current = current->next; // tro den node ke tiep      // khi tro den sinh vien cuoi cung , next current = nullptr -> vong lap dung lai.
    }
}

void timkiemsinhvien(string id)
{
    SinhVien* current = head;  // y het ben tren
    while(current)
    {
        if (current->id == id){
            cout << "Tim thay sinh vien sau: \n";
            cout << "ID: [" << current ->id <<"], " << "Ho va ten: [" << current->hoTen <<"], " <<"Ngay sinh: [" << current->ngaySinh <<"], " <<"GPA: [" <<current->gpa <<"]\n"; 
            // doan nay giong het ham` hien thi sinh vien ben tren nhe'
            return;
        }
        current = current->next;
    }
        cout<<"Khong tim thay sinh vien voi ma so nay! \n";
}

void gpacaonhat()
{
    if(!head){
        cout <<"Danh sach sinh vien hien dang trong.\n";
        return;
    }
    SinhVien* current = head; // van giong ben tren
    SinhVien* maxgpa = head; // lưu trữ node của sinh viên có gpa cao nhất , giả định sv đầu tiên có gpa cao nhất.
    while(current){
        if(current->gpa > maxgpa->gpa) { // neu gpa cua sv current > gpa cua maxgpa , thi gpa cua sv current = maxgpa. 
            maxgpa = current;
        }
        current = current->next;
    }
    cout <<"Sinh vien co gpa cao nhat:\n ";
    cout << "ID: [" << maxgpa ->id <<"], " << "Ho va ten: [" << maxgpa->hoTen <<"], " <<"Ngay sinh: [" << maxgpa->ngaySinh <<"], " <<"GPA: [" <<maxgpa->gpa <<"]\n"; 
     // doan nay giong het ham` hien thi sinh vien ben tren nhe'
}

void gpathapnhat() // giong het gpacaonhat chi thay max = min @@@
{
  if(!head){
        cout <<"Danh sach sinh vien hien dang trong.\n";
        return;
    }
    SinhVien* current = head; 
    SinhVien* mingpa = head; 
    while(current){
        if(current->gpa < mingpa->gpa) { 
            mingpa = current;
        }
        current = current->next;
    }
    cout <<"Sinh vien co gpa thap nhat:\n ";
    cout << "ID: [" << mingpa ->id <<"], " << "Ho va ten: [" << mingpa->hoTen <<"], " <<"Ngay sinh: [" << mingpa->ngaySinh <<"], " <<"GPA: [" <<mingpa->gpa <<"]\n"; 

}
};
void hienthimenu()
{
    cout << "----- MENU -----\n";
    cout << "[1] Them sinh vien moi\n";
    cout << "[2] Hien thi danh sach sinh vien\n";
    cout << "[3] Tim kiem sinh vien theo ID\n";
    cout << "[4] Sinh vien co GPA cao nhat\n";
    cout << "[5] Sinh vien co GPA thap nhat\n";
    cout << "[6] Thoat chuong trinh\n";
    cout << "----------------\n";
    cout << "Vui long chon chuc nang: ";
}

int main()
{
    Danhsachsinhvien danhSach;
    int luachon;
    do 
    {
        hienthimenu();
        cin >> luachon;
        switch(luachon){
            case 1: {
            string _id , _hoTen, _ngaySinh;
            double _gpa;
            cout<<"Nhap ID: ";
            cin >> _id;
            cin.ignore();
            cout<<"Nhap ho va ten sinh vien: ";
            getline(cin,_hoTen);
            cout << "Nhap ngay sinh (dd/mm/yyyy):";
            cin >> _ngaySinh;
            cin.ignore();
            cout << "Nhap diem trung binh: ";
            cin >> _gpa;
            danhSach.themsinhvien(_id, _hoTen,_ngaySinh,_gpa);
            break;
            }
            case 2:
            danhSach.hienthisinhvien();
            break;
        case 3: {
            string ma;
            cout << "Nhap ma so sinh vien can tim: ";
            cin >> ma;
            danhSach.timkiemsinhvien(ma);
            break;
        }
        case 4:
            danhSach.gpacaonhat();
            break;
        case 5:
            danhSach.gpathapnhat();
            break;
        case 6:
            cout << "THOAT CHUONG TRINH \n";
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }

    } while(luachon != 6);
    return 0;
}