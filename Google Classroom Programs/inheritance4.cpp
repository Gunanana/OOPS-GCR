//4. Write a C++ program to define a base class Item (item-no, name, price). Derive a class Discounted-Item (discount-percent). A customer purchases 'n' items. Display the item-wise bill and total amount using appropriate format.

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
class item;
class discountedItem;
vector<discountedItem> cart;

class item{
protected:
    int ino;
    double price;
    string name;
    public:
    item(){
        cout<<"Enter Item no: "; cin>>ino;
        cout<<"Enter Item name: "; cin>>name;
        cout<<"Enter Item price: "; cin>>price;
    }
    item(int a, double p, string n):ino(a),price(p),name(n){}
};

class discountedItem: public item{
    double discountPercent, finalPrice;
    public:
    friend void buy();
    friend void generateBill();
    friend void menu();
    discountedItem(){
        cout<<"Enter Discount percent: "; cin>>discountPercent;
        finalPrice=price*(1-discountPercent/100);
    }
    discountedItem(int a, double p, string n,double dp):item(a,p,n),discountPercent(dp) {finalPrice=price*(1-discountPercent/100);}
};
void buy(){
    discountedItem item;
    cart.push_back(item);
}

void generateBill(){
    double totalAmountd=0;
    double totalAmount=0;
    cout<<"\n\n\n\n------BILL------"<<endl;
    for(auto i : cart){
        cout<<i.ino<<") "<<setw(10)<<left<<i.name<<"\t"<<"Rs. "<<i.price<<"\t"<<endl;
        totalAmountd += i.finalPrice;
        totalAmount += i.price;
    }
    cout<<endl<<setw(15)<<left<<"Total Amount "<<"  Rs."<<setprecision(2)<<totalAmount<<endl;
    cout<<setw(15)<<left<<"Discount  "<<"- Rs."<<setprecision(2)<<totalAmount-totalAmountd<<endl;
    cout<<string(30,'-')<<endl;
    cout<<setw(15)<<left<<"Final Amount " <<"= Rs."<<setprecision(2)<<totalAmountd<<endl;
}

void menu(){
    int response;
    while(true){
        cout<<"Menu:  \n1. Buy\n2. Generate Bill and Exit\n3. Exit\n";
        cin>>response;
        switch (response){
            case 1: buy();break;
            case 2: generateBill(); exit(0);
            case 3: exit(0);
        }
    }
}

int main(){
    menu();
    return 0;
}
