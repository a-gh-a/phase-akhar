#ifndef CLASS_USER_H_INCLUDED
#define CLASS_USER_H_INCLUDED

using namespace std;

class User {
protected:
    int userID;
    string name, lastName;
    string hashedPassword;

public:

    User(int id, string n, string ln, string pwd) : userID(id), name(n), lastName(ln), hashedPassword(pwd) {}

    User() : userID(0), name(""), lastName(""), hashedPassword("") {};


    // Getters
    int getUserID() const { return userID; }
    string getName() const { return name; }
    string getLastName() const { return lastName; }
    string getHashedPassword() const { return hashedPassword; }

    void setPassword(const std::string& pass) {
    hashedPassword = pass;
}

    // Setters
    void setName(string n) { name = n; }
    void setLastName(string ln) { lastName = ln; }
    void setHashedPassword(string pwd) { hashedPassword = pwd; }


    virtual void print() const {
        cout << "User ID: " << userID << ", Name: " << name << " " << lastName << endl;
    }
};


// توابع مربوط به تعاملات کاربری
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addReservation();
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
  //  void cancelReservation(){cancel();};


#endif // CLASS_USER_H_INCLUDED
