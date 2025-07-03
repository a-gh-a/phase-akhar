#ifndef DIN_HALL_H_INCLUDED
#define DIN_HALL_H_INCLUDED

using namespace std;

class din {
private:
    int hall_id;
    string address;
    int capacity;

public:

    din() : hall_id(0), address(""), capacity(0) {};


    void print() const {
        cout << "Dining Hall: " << address << ", Capacity: " << capacity << endl;
    }

    void input(){
        set_hall_id();
        set_address();
        set_capacity();
                }

    // Setters with validation
    void set_hall_id() { cout<<"enter id:";cin>>hall_id; }
    void set_address() { cout<<"enter address:";cin>>address; }
    void set_capacity() {
         for(int i=0;i<1;)
            {
                cout<<"enter capacity:";
                cin>>capacity;
                if (capacity > 0) { i++;}


                 else cout<<endl<<"enter again";
            }
    }

    // Getters
    int get_hall_id() const { return hall_id; }
    string get_address() const { return address; }
    int get_capacity() const { return capacity; }
};




#endif // DIN_HALL_H_INCLUDED
