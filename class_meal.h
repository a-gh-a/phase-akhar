#ifndef CLASS_MEAL_H_INCLUDED
#define CLASS_MEAL_H_INCLUDED


using namespace std;

enum MealType { BREAKFAST, LUNCH, DINNER };
enum day {MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY};

class M
 {
private:
    int meal_id;
    string name;
    MealType type;
    float price;
    day day_Re;

public:


    void print() const {
        cout << "Meal: " << name << ", Type: " << type << ", Price: " << price <<",day:"<<day_Re<< endl;
    }


    void input(){
        set_meal_id();
        set_name();
        set_type();
        set_price();
        set_day();
        }

    // Setters with validation
    void set_meal_id() {
        cout<<"enter meal_id:";
        cin>>meal_id;
         }


    void set_name() {
        cout<<"enter meal_name:";
        cin>>name;
         }


    void set_type() {
         int i;
         cout<<"enter type meal:(1,2,3)";
         cin>>i;
          if(i==1) type=BREAKFAST;
          if(i==2) type=LUNCH;
          if(i==3) type=DINNER;
          }




    void set_price() {

        for(int i=0;i<1;)
            {
                cout<<"enter price:";
                cin>>price;
                if (price > 0) { i++;}


                 else cout<<endl<<"enter agin";
            }
    }

    void set_day(){
    int i;
    cout<<"enter day(1,2,3,4,5):";
    cin>>i;
    if(i==1)day_Re=MONDAY;
    if(i==2)day_Re=TUESDAY;
    if(i==3)day_Re=WEDNESDAY;
    if(i==4)day_Re=THURSDAY;
    else day_Re=FRIDAY;


    }

    // Getters
    int get_meal_id() const { return meal_id; }
    string get_name() const { return name; }
    MealType get_type() const { return type; }
    float get_price() const { return price; }
    day get_day() const {return day_Re;}


};


#endif // CLASS_MEAL_H_INCLUDED
