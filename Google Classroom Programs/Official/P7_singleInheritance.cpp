//Inheritance and Constructors: Design a class named PersonData with the following member variables: lastName, firstName,  address, city, state and phone.  Write the appropriate constructor, accessor and mutator functions. Next, design a class named CustomerData, which is derived from the PersonData class.  The CustomerData class has member variables: customerNumber and email id. The customerNumber variable holds a unique integer for each customer. Write appropriate constructors, accessor and mutator functions. Demonstrate an object of the CustomerData class in retrieving individual customer data.


#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class personData{
    protected:
    string ln,fn,ad,city,state;
    long long ph;
    personData(){
        cout<<"Enter your personal detais below\n";
        cout<<"First name: ";cin>>fn;
        cout<<"Last name: ";cin>>ln;
        cout<<"Address: ";cin>>ad;
        cout<<"City: ";cin>>city;
        cout<<"State: ";cin>>state;
        cout<<"Phone number: ";cin>>ph;
    }
    personData(string l,string f,string a,string c,string s,long long p):ln(l),fn(f),ad(a),city(c),state(s),ph(p){}
    void display(){
        cout<<"\n\nDetails\n";
        cout<<"Name: "<<fn<<" "<<ln<<endl;
        cout<<"Address: "<<ad<<", "<<city<<", "<<state<<endl;
        cout<<"Phone Number: "<<ph<<endl;
    }
};

class customerData:public personData{
    int cn;
    string email;
    public:
    customerData(){
        cout<<"Customer Number: ";cin>>cn;
        cout<<"Email ID: ";cin>>email;
    }
    customerData(string l,string f,string a,string c,string s,long long p,int number,string e):personData( l, f, a, c, s, p),cn(number),email(e){}
    void display(){
        personData::display();
        cout<<"Customer Number: "<<cn<<endl;
        cout<<"Email: "<<email<<endl;
    }
};

int main(){
    customerData guna;
    guna.display();
}