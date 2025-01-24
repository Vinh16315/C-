#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;        
    string name;       
    string birthDate;  
    float gpa;         
};

void addStudent(Student students[], int &count) {
    if (count >= 100) {
        cout << "Danh sach sinh vien da day!" << endl;
        return;
    }
    cout << "Nhap ma so sinh vien: ";
    cin >> students[count].id;
    cout << "Nhap ho ten sinh vien: ";
    cin.ignore(); 
    getline(cin, students[count].name);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin >> students[count].birthDate;

    float gpa;
    do {
        cout << "Nhap diem trung binh : ";
        cin >> gpa;
        if (gpa < 0 || gpa > 10) { 
            cout << "Diem trung binh khong hop le! Vui long nhap lai." << endl;
        }
    } while (gpa < 0 || gpa > 10);
    
    students[count].gpa = gpa;
    count++;
    cout << "Them sinh vien thanh cong!" << endl;
}

void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "Khong co sinh vien nao!" << endl;
        return;
    }
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < count; i++) {
        cout << "Ma so: " << students[i].id
             << ", Ho ten: " << students[i].name
             << ", Ngay sinh: " << students[i].birthDate
             << ", Diem TB: " << students[i].gpa << endl;
    }
}

void searchStudent(const Student students[], int count) {
    string id;
    cout << "Nhap ma so sinh vien can tim: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Tim thay sinh vien:\n";
            cout << "Ma so: " << students[i].id
                 << ", Ho ten: " << students[i].name
                 << ", Ngay sinh: " << students[i].birthDate
                 << ", Diem TB: " << students[i].gpa << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ma so " << id << endl;
}

void displayHighestGPA(const Student students[], int count) {
    if (count == 0) {
        cout << "Khong co sinh vien nao!" << endl;
        return;
    }
    int highestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].gpa > students[highestIndex].gpa) {
            highestIndex = i;
        }
    }
    cout << "Sinh vien co diem trung binh cao nhat:\n";
    cout << "Ma so: " << students[highestIndex].id
         << ", Ho ten: " << students[highestIndex].name
         << ", Ngay sinh: " << students[highestIndex].birthDate
         << ", Diem TB: " << students[highestIndex].gpa << endl;
}

void displayLowestGPA(const Student students[], int count) {
    if (count == 0) {
        cout << "Khong co sinh vien nao!" << endl;
        return;
    }
    int lowestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].gpa < students[lowestIndex].gpa) {
            lowestIndex = i;
        }
    }
    cout << "Sinh vien co diem trung binh thap nhat:\n";
    cout << "Ma so: " << students[lowestIndex].id
         << ", Ho ten: " << students[lowestIndex].name
         << ", Ngay sinh: " << students[lowestIndex].birthDate
         << ", Diem TB: " << students[lowestIndex].gpa << endl;
}

int main() {
    Student students[100]; 
    int count = 0;         
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi tat ca sinh vien\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Hien thi sinh vien co diem trung binh cao nhat\n";
        cout << "5. Hien thi sinh vien co diem trung binh thap nhat\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                displayHighestGPA(students, count);
                break;
            case 5:
                displayLowestGPA(students, count);
                break;
            case 0:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
        }
    } while (choice != 0);

    return 0;
}
