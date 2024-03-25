#include<iostream>
using namespace std;

class complex{
    int r,i;
    public:
    complex(){
        cout<<"Inside default constructor\n";
    }
    complex(int real, int imag):r(real), i(imag){}
    void hey(){cout<<"Hey\n";}
};

int main(){
    complex *bptr[3];
    bptr[0]=new complex;
    (*bptr[0]).hey();
    return 0;
}