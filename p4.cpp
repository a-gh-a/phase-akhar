#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <cstdlib>
#include<windows.h>

#include "class_meal.h"
#include "class_din_hall.h"
#include "class_user.h"
#include "class_student.h"
#include "class_reservation.h"
#include "class_transaction.h"
#include "class_shop.h"

using namespace std;

Student stu1;
din d1;
M me1;
ShoppingCart sh1;
vector<Reservation> re1;

void clearConsole() {
    system("cls"); // فقط در ویندوز
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

void P() {
    int k;
    cout << "\n1. Display student information\n";
    cout << "2. Show credit\n";
    cout << "3. View reservations\n";
    cout << "4. Add reservation\n";
    cout << "5. Add to cart\n";
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
        // stu1.showCredit(); // اگر تابعی برای نمایش اعتبار دارید
        break;
    case 3:
        for (const auto& res : re1)
            res.viewReservations();
                    Sleep(5000);

        break;
    case 4: {
        Reservation r;
        r.input(stu1, me1, d1, re1);
        cout << "Reservation added.\n";
        break;
    }
    case 5:
        // sh1.addToCart(); // اگر پیاده‌سازی شده
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
    stu1.input();
    me1.input();
    d1.input();

    while (true) {
        P();
        clearConsole();
    }

    return 0;
}
