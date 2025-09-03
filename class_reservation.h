#ifndef CLASS_RESERVATION_H_INCLUDED
#define CLASS_RESERVATION_H_INCLUDED

#include "class_meal.h"
#include "class_din_hall.h"
#include "class_student.h"
#include "class_transaction.h"


using namespace std;

extern Student stu1;
extern din d1;
extern M me1;
extern Transaction TRA;
extern Student currentStudent;


enum ReservationStatus { SUCCESS, CANCELLED, FAILED };

class Reservation {
private:
    int reservation_id;
    Student studentt;
    M meall;
    din halll;
    ReservationStatus status;
    time_t created_at;

public:
    Reservation(int id, Student stu, M meal, din hall, ReservationStatus stat)
        : reservation_id(id), studentt(stu), meall(meal), halll(hall), status(stat), created_at(time(nullptr)) {}

    Reservation()
        : reservation_id(0), studentt(), meall(), halll(), status(FAILED), created_at(time(nullptr)) {}

    void viewReservations() const {
        cout << "Reservation ID: " << reservation_id
             << ", Student: " << studentt.get_name()
             << ", Meal: " << meall.get_name()
             << ",dining hall:"<<halll.get_address()
             << ", Status: " << status << endl;
    }

    void input(Student b2, M h1, din h2, vector<Reservation>& re1) {
        set_reservation_id();
        set_student(b2);
        set_meal(h1);
        set_hall(h2);
        set_status();

        re1.emplace_back(reservation_id, studentt, meall, halll, status);
    }

    void cancel() {
        int i;
        if (status == SUCCESS){

            status = CANCELLED;
            i=currentStudent.get_balance()+ meall.get_price();
            cout<<" you return to meno...";
            Sleep(2000);
            TRA.setAmount_by_file(i);

        }
        else
            cout << "cansel bod";
    }

    void set_reservation_id() {
        cout << "Enter reservation ID: ";
        cin >> reservation_id;
    }

    void set_reservation_id_by_file(int i) {reservation_id=i;}

    void set_student(Student b1) { studentt = b1; }
    void set_meal(M h1) { meall = h1; }
    void set_hall(din h2) { halll = h2; }

    void set_status() {
        if (TRA.get_status_T()==COMPLETED){ status = SUCCESS; cout<<"reservation is SUCCESS"<<endl<<" you return to meno..."; Sleep(2000);}
        if (TRA.get_status_T()==FIALED){ status = FAILED; cout<<"reservation is FAILED"<<endl<<" you return to meno..."; Sleep(2000);}
        if (TRA.get_status_T()!=FIALED && TRA.get_status_T()!=COMPLETED ){ cerr << "error in ReservationStatus!"; Sleep(2000);}

    }

    void set_status_by_file(int i) {
        if (i==0) status = SUCCESS;
        if (i==1) status = CANCELLED;
        if (i==2) status = FAILED;
        //else cout << "error in ReservationStatus!";
    }


    int get_reservation_id() const { return reservation_id; }
    Student get_student() const { return studentt; }
    M get_meall() const { return meall; }
    din get_hall () const { return halll; }
    ReservationStatus get_status() const { return status; }
    time_t get_created_at() const { return created_at; }
};

extern vector<Reservation> re1;

#endif // CLASS_RESERVATION_H_INCLUDED
