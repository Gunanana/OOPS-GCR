/*Polymorphism: Develop a C++ program to create a class called COMPLEX with the following overloading functions ADD that return a COMPLEX number.
i. ADD (a, s2) – where a is an integer (real part) and s2 is a complex number.
ii. ADD (s1, s2) – where s1 and s2 are complex numbers.*/

#include<iostream>
using namespace std;

class complex{
    public:
    int r,i;
    complex(){
        cout<<"Real part: ";cin>>r;
        cout<<"Imaginary Part: ";cin>>i;
    }
    complex(int x, int y):r(x),i(y){}
    friend complex add(const int &a, const complex &s2){return complex(a+s2.r,s2.i);}
    friend complex add(const complex &s2, const complex &s1){ return complex(s1.r+s2.r,s1.i+s2.i);}
};

int main(){
    //i)
    int a=10;
    complex s1(10,15);
    complex sum= add(a,complex(4,6));
    cout<<sum.r<<"+ ("<<sum.i<<") i"<<endl;
    //ii)
    complex s3(1,2);
    complex s4= add(s1,s3);
    cout<<s4.r<<"+ ("<<s4.i<<") i"<<endl;
    return 0;
}