/*Friend function: Create two classes, Class RollsRoyce and Class Lamborghini with appropriate member variables (Model name, year, price and mileage) and member functions (read and print). Demonstrate the comparison of two cars w.r.t price and mileage using friend function.*/

#include<iostream>
using namespace std;

class rr;
class lambo;

class rr{
    string name;
    int year;
    double price, mileage;
    public:
    friend void compare(const rr &r,const lambo &l);
};

class lambo{
    string name;
    int year;
    double price, mileage;
    public:
    friend void compare(const rr &r,const lambo &l);
};

void compare(const rr &r,const lambo &l){
    if(r.price < l.price) cout<<"RR is less expensive\n";
    else  if (r.price > l.price) cout<<"Lambo is less expensive\n";
    else cout<<"They both cost the same\n";

    if(r.mileage < l.mileage) cout<<"RR has more miles on it\n";    
    else if(r.mileage > l.mileage) cout<<"Lambo has more miles on it\n";
    else cout<<"Both have the same number of miles\n";  
}