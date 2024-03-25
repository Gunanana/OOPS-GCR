/*Static and non-static members: Create a vehicle having a non-static data member registration number and a static data member count. Non-static member functions setregno() and getregno() are used to get and set the registration number. A static member function getVehiclecount() is used to return the number of vehicles in the garage. Use a constructor to increment the vehicle count when a vehicle is created and the destructor to decrement the count when the vehicle is destroyed.*/

#include<iostream>
using namespace std;

class vehicles{
    int regno;
    static int count;
    public:
    vehicles(int r):regno(r){count++;}
    ~vehicles(){--count;}
};
int vehicles:: count;