#ifndef CLASS_TRANSACTION_H_INCLUDED
#define CLASS_TRANSACTION_H_INCLUDED

using namespace std;

enum  TransactionType {PAYMENT,TRANSFER};

enum  TransactionStatus {PENDING,COMPLETED,FIALED};

class Transaction {
private:
    int transactionID;
    string trackingCode;
    float amount;
    TransactionType type;
    TransactionStatus status;
    time_t createdAt;
public:

    Transaction() {
    transactionID = rand();
    trackingCode = "TX-" + to_string(transactionID);
    amount = 0.0;
    type =PAYMENT;
    status = PENDING;
    createdAt = time(nullptr);
}


    int getTransactionID() const { return transactionID; };
    string getTrackingCode() const { return trackingCode; };
    float getAmount() const { return amount; };
    TransactionType getType() const { return type; };
    TransactionStatus getStatus() const { return status; };
    time_t getCreatedAt() const { return createdAt; };


    void setAmount()  {
        cout<<"enter amount:"<<endl;
        cin>>amount;
        };



    void setType()  {
        int i;
        cout<<"enter type of tra (1.PAYMENT,2.TRANSFER)"<<endl;
        cin>>i;
        if(i==1) type=PAYMENT;
        else type=TRANSFER;
     };


    void setStatus(TransactionStatus status){
        int i;
        cout<<"enter status (1.PENDING,2.COMPLETED,3.FIALED)"<<endl;
        cin>>i;
        if(i==1) status=PENDING;
        if(i==2) status=COMPLETED;
        else status=FIALED;

    };
};




#endif // CLASS_TRANSACTION_H_INCLUDED
