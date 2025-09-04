#ifndef CLASS_USER_H_INCLUDED
#define CLASS_USER_H_INCLUDED

using namespace std;

class User {
protected:
    string userID;
    string name, lastName;
    string hashedPassword;

public:

    User(string id, string n, string ln, string pwd) : userID(id), name(n), lastName(ln), hashedPassword(pwd) {}

    User() : userID(""), name(""), lastName(""), hashedPassword("") {};


    // Getters
    string getUserID() const { return userID; }
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



#endif // CLASS_USER_H_INCLUDED
