//Develop a C++ program to perform bank transactions like 1.check balance, 2.withdraw and 3.deposit. Use appropriate control structures and incorporate the topics learnt in class today wherever required. Topics covered are : reference variables, memory management operators, default arguments, inline function, manipulators.


#include<bits/stdc++.h>
using namespace std;

class bankAccount{
    string name,ans;
    int uid,i=0;
    float bal=0,mbal=3000,money=0;
    public:
    inline void start(){
        while(1){
        cout<<"\n\nWelcome to GBI\nEnter valid number to avail our services\n";
        cout<<"(1) Open Account\n";
        cout<<"(2) Check Balance\n";
        cout<<"(3) Withdraw Money\n";
        cout<<"(4) Deposit Money\n";
        cout<<"(5) Show Account Details\n";
        cout<<"(6) Exiting\n";
        cin>>i;
        switch (i){
            case 0:
            cout<<"Enter valid number\n";
            this->start();
            case 1:
            setData();
            break;
            case 2:
            checkBalance();
            break;
            case 3:
            withdraw();
            break;
            case 4:
            deposit();
            break;
            case 5:
            getDetails();
            break;
            case 6:
            exit(0);
        }
        }
    }
    inline void setData(){
        cout<<"Enter your name\n";
        cin>>name;
        cout<<"Enter your UID\n";
        cin>>uid;
        cout<<"Account Opened Successfully!!\nDo you want to Deposit money?(y/n)\n";
        cin>>ans;
        //ans=tolower(ans);
        if(ans=="y"){
            deposit();
        }
        else{
            cout<<"Thankyou for Opening an Account\nSee you later :)\n";
        }
    }
    inline void checkBalance(){
        cout<<"Your balance is "<<fixed<<setprecision(2)<<bal;
    }
    inline void withdraw(){
        cout<<"How much Money do u want to withdraw?/n";
        cin>>money;
        if(money>bal){
            cout<<"Withdrawal amount exceeds Balance amount\n";
            withdraw();
        }
        else{
            bal-=money;
            cout<<money<<" INR has been withdrawn\n";
            cout<<"Current Balance is "<<bal;
        }
    }
    inline void deposit(){
        money=0;
        cout<<"Enter the amount you want to Deposit\n";
        cin>>money;
        this->bal+=money;
        cout<<money<<" INR was deposited into your account\nYour current balance is "<<fixed<<setprecision(2)<<bal<<endl;
}
    inline void getDetails(){
        cout<<"Your name is "<<this->name<<endl;
        cout<<"Your account number is "<<this->uid<<endl;
        cout<<"Your balance is "<<this->bal<<endl;
    }
};

int main(){
    bankAccount guna;
    guna.start();
    return 0;
}