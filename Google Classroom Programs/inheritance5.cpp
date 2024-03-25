/*5. Write class declarations and member function definitions for a C++ base class to represent an Employee (emp-code, name). Derive two classes as Fulltime (daily rate, number of days, salary) and Parttime (number of working hours, hourly rate, salary).
Write a menu driven program to:
1. Accept the details of ‘n’ employees.
2. Display the details of ‘n’ employees.
3. Search a given Employee by emp-code.
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class employee{
    int eno;
    string name;
public:
    employee(){
        cout<<"Enter employee name: "; cin>>name;
        cout<<"Enter employee number: "; cin>>eno;
    }
    employee(int e, string n): eno(e), name(n){}
    string getName(){return name;}
    int getNumber(){return eno;}
    friend void display(vector<partTime> pt, vector<fullTime> ft);
};

class fullTime:public employee{
    double drate, salary;
    int days;
public:
    fullTime(){
        cout<<"Enter daily rate: "; cin>>drate;
        cout<<"Enter salary: "; cin>>salary;
        cout<<"Enter number of days worked:"; cin>>days;
    }
    fullTime(int e, string n, double d, double s, int nd): employee(e,n),drate(d),salary(s),days(nd){}
    double getDrate(){return  drate;}
    double getSalary(){ return salary;}
    int getDays(){return days;}
    friend void display(vector<partTime> pt, vector<fullTime> ft);
};

class partTime:public employee{
    int hours;
    double hrate, salary;
public:
    partTime(){
        cout<<"Enter hourly rate: "; cin>>hrate;
        cout<<"Enter number of hours: "; cin>>hours;
        cout<<"Enter salary: "; cin>>salary;
    }
    partTime(int e, string n, int h, int hr, int s):employee(e,n),hours(h),hrate(hr),salary(s){}
    int getHours() {return hours;}
    double getHrate(){return hrate;}
    double getSalary(){return salary;}
    friend void display(vector<partTime> pt, vector<fullTime> ft);
};

vector<partTime> ptarr;
vector<fullTime> ftarr;

void display(vector<partTime> pt, vector<fullTime> ft){
    for(auto i: pt){
        cout<<"Employee name: "<<i.getName()<<endl;
    }
}