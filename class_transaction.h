#ifndef CLASS_TRANSACTION_H_INCLUDED
#define CLASS_TRANSACTION_H_INCLUDED


#include "class_student.h"

using namespace std;

//extern vector<Reservation> re1;
extern Student currentStudent;
extern M me1;


enum  TransactionType {PAYMENT,TRANSFER};

enum  TransactionStatus {COMPLETED,FIALED};

class Transaction {
private:
    int transactionID;
    string trackingCode;
    int amount;
    TransactionType type;
    TransactionStatus status_T;
    time_t createdAt;
public:

    Transaction() {
    transactionID = rand();
    trackingCode = "TX-" + to_string(transactionID);
    amount = 10;
    type =PAYMENT;
    status_T = FIALED;
    createdAt = time(nullptr);
}






    int getTransactionID() const { return transactionID; };
    string getTrackingCode() const { return trackingCode; };
     int getAmount() const { return amount; };
    TransactionType getType() const { return type; };
    TransactionStatus getStatus() const { return status_T; };
    time_t getCreatedAt() const { return createdAt; };


    void setAmount()  {
        amount=10;
        };

    void setAmount_by_file(int i) {amount=i;};



    void setType()  {
        int i;
        cout<<"enter type of tra (1.PAYMENT,2.TRANSFER)"<<endl;
        cin>>i;
        if(i==1) type=PAYMENT;
        else type=TRANSFER;
     };


    void setStatus(){
        if(me1.get_price()<amount || me1.get_price()==amount){ status_T=COMPLETED;  amount=amount-me1.get_price();}
        if(me1.get_price()>amount) status_T=FIALED;
        //else cerr<<"error in Transaction status";
    };


    TransactionStatus get_status_T(){return status_T;}


};




#endif // CLASS_TRANSACTION_H_INCLUDED
