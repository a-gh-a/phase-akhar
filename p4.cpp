#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <cstdlib>
#include<windows.h>
#include <fstream>
#include <sstream>
#include <set>


#include "class_meal.h"
#include "class_din_hall.h"
#include "class_user.h"
#include "class_student.h"
#include "class_reservation.h"
#include "class_transaction.h"
#include "class_shop.h"

using namespace std;

//userID,studentID,name,lastname,hashpassword,email,phone
//Student stu1;
din d1;
M me1;
ShoppingCart sh1;
vector<Reservation> re1;
Transaction TRA;
Student currentStudent;
string sfile;


void clearConsole() {
    system("cls"); // فقط در ویندوز
}





vector<Student> loadStudentsFromCSV(const string& studentsCsvFile) {
    vector<Student> students;
    ifstream file(studentsCsvFile);
    string line;
    bool isHeader = true;
    string userID, studentID, name, lastname, hashpassword, email, phoneStr;
    while (getline(file, line)) {
        if (isHeader) { isHeader = false; continue; }

        stringstream ss(line);
        getline(ss, userID, ',');
        getline(ss, studentID, ',');
        getline(ss, name, ',');
        getline(ss, lastname, ',');
        getline(ss, hashpassword, ',');
        getline(ss, email, ',');
        getline(ss, phoneStr, ',');


        Student s;
        s.setUserID(userID);
        s.set_student_id(stoll(studentID));
        s.setName(name);
        s.setLastName(lastname);
        s.setPassword(hashpassword);
        s.set_email_direct(email);
        s.set_phone_direct(stoll(phoneStr));
        s.set_balance(); // مقدار پیش‌فرض یا از فایل جداگانه



        students.push_back(s);
    }


    return students;
}

class Admin : public Student {
public:
    void activateUser(User& user) {
        cout << "User: " << user.getName() << endl;
        set_active();
    }

    void print() const {
        cout << "Admin ID: " << getUserID()
             << ", Name: " << getName() << " " << getLastName() << endl;
    }
};


Student loginMenu(const vector<Student>& s) {
    long long inputID;
    cout << "Enter your student ID: ";
    cin >> inputID;

for(size_t i=0;i<s.size();i++){
        if (s[i].get_student_id() == inputID) {
            cout << "Welcome, " << s[i].get_name() << "!\n";
            return s[i];
        }
      }

    cout << "Student not found. Exiting...\n";
    exit(1);
}



void P(Student & stu1) {
    int k;
    cout << "\n1. Display student information\n";
    cout << "2. Show credit\n";
    cout << "3. View reservations\n";
    cout << "4. Add reservation\n";
    cout << "5.  \n";
    cout << "6. Purchase confirmation\n";
    cout << "7. Cancel the reservation\n";
    cout << "8. EXIT\n";
    cout << "Choose: ";
    cin >> k;

    switch (k) {
    case 1:
        stu1.showStudentInfo();
        Sleep(5000);
        break;
    case 2:
         cout<<TRA.getAmount();
         Sleep(5000);

        break;
    case 3:
        for (const auto& res : re1)
            res.viewReservations();
            cout<<sfile;
                    Sleep(5000);

        break;
    case 4:{
        Reservation r;
        me1.input();
        d1.input();
        TRA.setStatus();
        r.input(stu1, me1, d1, re1);



        // ذخیره‌سازی اطلاعات در فایل
        ofstream outFile(sfile, ios::app); // فایل را در حالت الحاق باز می‌کند
        if (outFile.is_open()) {
            outFile << r.get_reservation_id()
                    << "," << r.get_student().get_name()
                    << "," << r.get_meall().get_name()
                    << "," << r.get_hall ().get_address()
                    << "," << r.get_status()<< endl;
            outFile.close(); // بستن فایل
        } else cout << "Unable to open file";


        cout << "Reservation added.\n";
        break;
    }
    case 5:

        break;
    case 6:
        // sh1.confirmPurchase(); // اگر پیاده‌سازی شده
        break;
    case 7:
        if (!re1.empty()) {
            re1.back().cancel();
            cout << "Last reservation cancelled.\n";
        } else {
            cout << "No reservations to cancel.\n";
        }
        break;
    case 8:
        exit(0);
    default:
        cout << "Invalid option.\n";
    }
}

int main() {
    vector<Student> students = loadStudentsFromCSV("studentsCsvFile.csv");
    currentStudent = loginMenu(students);
    srand(time(nullptr)); // مقداردهی اولیه به rand

    TRA.setAmount();
    sfile="stu"+currentStudent.getUserID()+".txt";

    while (true) {
        P(currentStudent);
        clearConsole();
    }

    return 0;
}
