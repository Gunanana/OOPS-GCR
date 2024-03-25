//Friend function: Create two classes, Class RollsRoyce and Class Lamborghini with appropriate member variables (Model name, year, price and mileage) and member functions (read and print). Demonstrate the comparison of two cars w.r.t price and mileage using friend function.

#include<bits/stdc++.h>
using namespace std;
class RollsRoyce;
class Lamborghini;

class RollsRoyce{
    int year,p,m;
    string name;
    public:
    RollsRoyce();
    RollsRoyce(int y,int price,int mil,string n):year(y),p(price),m(mil),name(n){}
    friend void printer(RollsRoyce r1);
    friend void compare(RollsRoyce r1,Lamborghini l1);
    friend void compare(Lamborghini l1,RollsRoyce r1);
};

class Lamborghini{
    int year,p,m;
    string name;
    public:
    Lamborghini();
    Lamborghini(int y,int price,int mil,string n):year(y),p(price),m(mil),name(n){}
    friend void printer(Lamborghini l1);
    friend void compare(RollsRoyce r1,Lamborghini l1);
    friend void compare(Lamborghini l1,RollsRoyce r1);

};

RollsRoyce:: RollsRoyce(){
    cout<<"Enter your RollsRoyce model name: ";
    cin>>name;
    cout<<"Enter the price: ";
    cin>>p;
    cout<<"Enter the mileage: ";
    cin>>m;
    cout<<"Enter year manufactured: ";
    cin>>year;
}

Lamborghini::Lamborghini(){
    cout<<"Enter your Lamborghini model name: ";
    cin>>name;
    cout<<"Enter the price: ";
    cin>>p;
    cout<<"Enter the mileage: ";
    cin>>m;
    cout<<"Enter year manufactured: ";
    cin>>year;
}

void printer(RollsRoyce r1){
    cout<<"Your car model name is "<<r1.name<<endl;
    cout<<"Your car's mileage is "<<r1.m<<endl;
    cout<<"Your car's price is "<<r1.p<<endl;
    cout<<"Your car was released in the year: "<<r1.year<<endl;
}

void printer(Lamborghini l1){
    cout<<"Your car model name is "<<l1.name<<endl;
    cout<<"Your car's mileage is "<<l1.m<<endl;
    cout<<"Your car's price is "<<l1.p<<endl;
    cout<<"Your car was released in the year: "<<l1.year<<endl;
}

void compare(Lamborghini l1, RollsRoyce r1){
    if(r1.p>l1.p) cout<<r1.name<<" is costlier than "<<l1.name<<" by "<<(r1.p-l1.p)<<" USD."<<endl;
    else if(l1.p==r1.p) cout<<l1.name<<" costs same as "<<r1.name<<endl;
    else cout<<l1.name<<" is costlier than "<<r1.name<<" by "<<(l1.p-r1.p)<<" USD."<<endl;
    if(r1.m>l1.m) cout<<r1.name<<" gives more mileage than "<<l1.name<<" by "<<(r1.m-l1.m)<<" kms."<<endl;
    else if(r1.p==l1.p) cout<<l1.name<<" gives same mileage as "<<r1.name<<endl;
    else cout<<l1.name<<" gives more mileage than "<<r1.name<<" by "<<(l1.m-r1.m)<<" kms."<<endl;
}
void compare(RollsRoyce r1,Lamborghini l1){
    if(r1.p>l1.p) cout<<r1.name<<" is costlier than "<<l1.name<<" by "<<(r1.p-l1.p)<<" USD."<<endl;
    else if(l1.p==r1.p) cout<<l1.name<<" costs same as "<<r1.name<<endl;
    else cout<<l1.name<<" is costlier than "<<r1.name<<" by "<<(l1.p-r1.p)<<" USD."<<endl;
    if(r1.m>l1.m) cout<<r1.name<<" gives more mileage than "<<l1.name<<" by "<<(r1.m-l1.m)<<" kms."<<endl;
    else if(r1.p==l1.p) cout<<l1.name<<" gives same mileage as "<<r1.name<<endl;
    else cout<<l1.name<<" gives more mileage than "<<r1.name<<" by "<<(l1.m-r1.m)<<" kms."<<endl;
}



int main(){
    Lamborghini a(1907,5000000,20,"Aventador");
    RollsRoyce c(1907,17000000,25,"Specter");
    compare(a,c);
    return 0;
}
