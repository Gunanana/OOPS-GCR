/*Create a class shape with member variables dimension and member function:
getDimension() to return dimension member variable and pure virtual function calculateArea().
Create square class which inherits the shape class and calculates the area of square.
Create circle class which inherits the shape class and calculates the area of circle.
Demonstrate runtime polymorphism in the main function to calculate the area of square and circle.*/

#include<iostream>
using namespace std;

#define pi 3.14159256359

class shape{
    double dimension;
    public:
    shape(){cout<<"Dimension: "; cin>>dimension;}
    shape(double dim): dimension(dim){}
    double getDimension(){return dimension;}
    virtual double calculateArea()=0; //Pure Virtual Function
};

class square: public shape{
    public:
    square(){}
    square(double dim) :shape(dim){}
    double calculateArea(){return getDimension()*getDimension();}
};

class circle: public shape{
    public:
    circle(){}
    circle(double dim) :shape(dim){}
    double calculateArea(){return pi*getDimension()*getDimension();}
};

int main(){
   shape *bptr;
   square s1(10); 
   bptr=&s1;
   cout<<"Square's area is: "<<bptr->calculateArea()<<endl;
   
   circle c1(10);
   bptr=&c1;
   cout<<"Circle's area is: "<<bptr->calculateArea()<<endl;
}