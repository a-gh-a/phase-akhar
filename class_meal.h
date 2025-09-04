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
    int price;
    day day_Re;
    static set<int> used_ids; // نگهداری شناسه‌های قبلی


public:

    // سازنده‌ی ساده
    M(int id, const string& meal_name, MealType meal_type, int meal_price, day reservation_day)
        : meal_id(id), name(meal_name), type(meal_type), price(meal_price), day_Re(reservation_day) {}

    M() = default;



    void print() const {
        cout << "Meal: " << name << ", Type: " << type << ", Price: " << price <<",day:"<<day_Re<< endl;
    }


    void input(){
        set_meal_id();
        set_type();
        set_name();
        set_price();
        set_day();
        }

    // Setters with validation

    void set_meal_id_by_file(int i) {meal_id=i;}

    void set_meal_id() {


        int id;
        do {id = rand() % 9000 + 1000; }
             while (used_ids.find(id) != used_ids.end());

        meal_id = id;
        used_ids.insert(id);

        cout << "meal_id: " << meal_id << endl;

    }

    void set_name_by_file(string s) {name=s;}


    void set_name() {
        while(true){
        int i;
        if(type==BREAKFAST){
        cout<<"enter meal_name:(1.honey 2.egg)";
        cin>>i;
        if(i==1){name="honey";return;}
        if(i==2){name="egg";return;}
        }
        else{
        cout<<"enter meal_name:(1.gorme sabzi 2.istanboli)";
        cin>>i;
        if(i==1){name="gorme sabzi";return;}
        if(i==2){name="istanboli";return;}
            }
         }
    }



    void set_type() {
         int i;
         cout<<"enter type meal:(1.BREAKFAST,2.LUNCH,3.DINNER)";
         cin>>i;
          if(i==1) type=BREAKFAST;
          if(i==2) type=LUNCH;
          if(i==3) type=DINNER;
          }

           void set_type_by_file(int i) {

          if(i==0) type=BREAKFAST;
          if(i==1) type=LUNCH;
          if(i==2) type=DINNER;
          }




    void set_price() {
     if(type==BREAKFAST)price=1;
     else price=2;

    }

    void set_day(){
        while(true){
    int i;
    cout<<"enter day(1,2,3,4,5):";
    cin>>i;
    switch(i){
    case 1:day_Re=MONDAY;return;
    case 2:day_Re=TUESDAY;return;
    case 3:day_Re=WEDNESDAY;return;
    case 4:day_Re=THURSDAY;return;
    case 5:day_Re=FRIDAY;return;
    default:break;
    }
    }
    }


      void set_day_by_file(int i){
        while(true){

    switch(i){
    case 0:day_Re=MONDAY;return;
    case 1:day_Re=TUESDAY;return;
    case 2:day_Re=WEDNESDAY;return;
    case 3:day_Re=THURSDAY;return;
    case 4:day_Re=FRIDAY;return;
    default:break;
    }
    }
    }

    // Getters
    int get_meal_id() const { return meal_id; }
    string get_name() const { return name; }
    MealType get_type() const { return type; }
    int get_price() const { return price; }
    day get_day() const {return day_Re;}


};




#endif // CLASS_MEAL_H_INCLUDED
