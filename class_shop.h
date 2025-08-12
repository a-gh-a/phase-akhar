#ifndef CLASS_SHOP_H_INCLUDED
#define CLASS_SHOP_H_INCLUDED
#include "class_reservation.h"
#include "class_din_hall.h"
#include "class_meal.h"
#include "class_student.h"


using namespace std;

extern vector<Reservation> re1;


class ShoppingCart {
private:
    vector<Reservation> _reservations;
public:
    Transaction confirm();


void addReservation(Student& s, M& m, din& d, vector<Reservation>& re1) {
    Reservation newRes;
    newRes.input(s, m, d, re1);
    re1.push_back(newRes);
}

void removeReservation(int ID) {
    _reservations.erase(
        remove_if(_reservations.begin(), _reservations.end(),
                  [ID](const Reservation& res) { return res.get_reservation_id() == ID; }),
        _reservations.end());
}

void viewShoppingCartItems() const {
    for (const auto& res : _reservations) {
        cout << "Reservation ID: " << res.get_reservation_id()  << endl;
    }
}

void clear() {
    _reservations.clear();
}

vector<Reservation> getReservations() const {
    return _reservations;
}

};



#endif // CLASS_SHOP_H_INCLUDED
