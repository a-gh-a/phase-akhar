#ifndef DIN_HALL_H_INCLUDED
#define DIN_HALL_H_INCLUDED

using namespace std;

int capacity;


class din {
private:
    int hall_id;
    string address;

public:

    din() : hall_id(0), address("") {};


    void print() const {
        cout << "Dining Hall: " << address << ", Capacity: " << capacity << endl;
    }

    void input(){
        set_address();
        set_hall_id();
        set_capacity();
                }

    // Setters with validation
    void set_hall_id() {
        if(address=="golstan"){hall_id=1125;return;}
        if(address=="pradis"){hall_id=1126;return;}
        cout<<"error in id_hall"; }
    void set_address() {
         int i;
         while(true){
         cout<<"choose address:(1.golstan 2.pradis)";
         cin>>i;
         if(i==1){address="golstan";return;}
         if(i==2){address="pradis";return;}
         }}

    void set_address_by_file(string s){address=s;return;}


    void set_capacity() {
        if(hall_id==1125) {capacity=10;return;}
        if(hall_id==1126) {capacity=2;return;}
        cout<<"error in capacity";
    }

    void set_agen_capacity() {
        if(hall_id==1125) {capacity--;return;}
        if(hall_id==1126) {capacity--;return;}
        cout<<"error in capacity";
    }

    // Getters
    int get_hall_id() const { return hall_id; }
    string get_address() const { return address; }
    int get_capacity() const { return capacity; }
};




#endif // DIN_HALL_H_INCLUDED
