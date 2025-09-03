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
int amuot2;
bool fileexists;


set<int> M::used_ids = {0};

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
        s.set_balance(stoi("10")); // مقدار پیش‌فرض یا از فایل جداگانه



        students.push_back(s);
    }


    return students;
}


vector<Reservation> loadReservationsFrom(const string& sfile) {
    vector<Reservation> reservations;
    ifstream file(sfile);
    fileexists=file.good();
    string line;
   // bool isHeader = true;
    string reservationIDStr, studentIDStr, mealStr, hallStr, statusStr,blansStr,mealidStr,mealnameStr,mealtypeStr,mealpriceStr,mealdayStr;

     while (getline(file, line)) {
       // if (isHeader) {
           // isHeader = false;
           // continue;
        //}

        stringstream ss(line);
        getline(ss, reservationIDStr, ',');
        getline(ss, studentIDStr, ',');
        getline(ss, mealStr, ',');
        getline(ss, hallStr, ',');
        getline(ss, blansStr, ',');
        getline(ss, mealidStr, ',');
        getline(ss, mealnameStr, ',');
        getline(ss, mealtypeStr, ',');
        getline(ss, mealpriceStr, ',');
        getline(ss, mealdayStr, ',');
        getline(ss, statusStr, ',');

        Reservation r;
        r.set_reservation_id_by_file(stoi(reservationIDStr));

        // فرض بر این است که متد getStudentById وجود دارد که دانشجو را با شناسه آن برمی‌گرداند
        r.set_student(currentStudent);
       // r.get_student().setName(studentIDStr);


        // فرض بر این است که متد getMealByName وجود دارد که غذا را با نام آن برمی‌گرداند
        me1.set_meal_id_by_file(stoi(mealidStr));
        me1.set_name_by_file(mealnameStr);
        me1.set_type_by_file(stoi(mealtypeStr));
        me1.set_price();
        me1.set_day_by_file(stoi(mealdayStr));
        r.set_meal(me1);


        // فرض بر این است که متد getHallByName وجود دارد که سالن را با نام آن برمی‌گرداند

        d1.set_address_by_file(hallStr);
        d1.set_hall_id();
        d1.set_capacity();
        r.set_hall(d1);

        //ذخیره موحودی

        if(fileexists)TRA.setAmount_by_file(stoi(blansStr));
        else TRA.setAmount_by_file(10);

        // فرض بر این است که Enum یا نوعی برای وضعیت رزرو وجود دارد

        r.set_status_by_file(stoi(statusStr));

        reservations.push_back(r);
    }

    return reservations;
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

                    Sleep(5000);

        break;
    case 4:{
        Reservation r;
        me1.input();
        d1.input();
        TRA.setStatus();
        r.input(stu1, me1, d1, re1);
        stu1.set_balance(TRA.getAmount());




        // ذخیره‌سازی اطلاعات در فایل
        ofstream outFile(sfile, ios::app); // فایل را در حالت الحاق باز می‌کند
        if (outFile.is_open()) {
            outFile << r.get_reservation_id()
                    << "," << r.get_student().get_name()
                    << "," << r.get_meall().get_name()
                    << "," << r.get_hall ().get_address()
                    << "," << TRA.getAmount()
                    << "," << me1.get_meal_id()
                    << "," << me1.get_name()
                    << "," << me1.get_type()
                    << "," << me1.get_price()
                    << "," << me1.get_day()
                    << "," << r.get_status()<< endl;
            outFile.close(); // بستن فایل
        } else cout << "Unable to open file";



        break;
    }
    case 5:

        break;
    case 6:
        // sh1.confirmPurchase(); // اگر پیاده‌سازی شده
        break;
    case 7:{
         int i;
         i=1;
         for (const auto& res : re1) {


            cout<<i<<"____";
            res.viewReservations();
            i++;
            }

            cout<<endl<<"enter number of Reservations for Cancel : ";
            cin>>i;
            i--;
            re1[i].cancel();
            currentStudent.set_balance(TRA.getAmount());



        break;
    }
    case 8:
        {

        ofstream file(sfile, ios::trunc);
        for (const auto& res : re1){

          // ذخیره‌سازی اطلاعات در فایل
        if (file.is_open()) {
            file << res.get_reservation_id()
                    << "," << res.get_student().get_name()
                    << "," << res.get_meall().get_name()
                    << "," << res.get_hall ().get_address()
                    << "," << TRA.getAmount()
                    << "," << me1.get_meal_id()
                    << "," << me1.get_name()
                    << "," << me1.get_type()
                    << "," << me1.get_price()
                    << "," << me1.get_day()
                    << "," << res.get_status()<< endl;
        } else{ cout << "Unable to open file"; Sleep(2000);}

        }
        file.close(); // بستن فایل


        exit(0);
        }
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

    re1=loadReservationsFrom(sfile);


    currentStudent.set_balance(TRA.getAmount());





         //    cout<< ", Student: " << re1[1].get_student().get_name()
          //   << ", Meal: " << re1[1].get_meall().get_name()
           //  << ",dining hall:"<<re1[1].get_hall().get_address();

    while (true) {
        P(currentStudent);
        clearConsole();
    }

    return 0;
}
