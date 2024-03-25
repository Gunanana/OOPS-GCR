/*Simple Classes and Objects: Create an EMPLOYEE class with the following members: Employee ID(Integer type), Employee Name, Basic, DA, IT, Net Salary. Member functions: to read the data, to calculate Net Salary and to print data members. Develop C++ program to demonstrate reading N employees information and compute Net Salary of each employee. (Consider Dearness Allowance (DA) = 52% of Basic and Income Tax (IT) = 30% of the gross salary. Net Salary = Basic + DA - IT).*/

#include<iostream>
using namespace std;

class employee{
    int eid;
    string name;
    double bsal,nsal;
    public:
    employee(){
        setData();
        displayData();
        cout<<"Their net salary is INR "<<netSalary()<<endl;
    }
    void setData(){
        cout<<"\nEnter the employee details\n";
        cout<<"Name: ";cin>>name;
        cout<<"ID: "; cin>>eid;
        cout<<"Enter Basic salary: "; cin>>bsal;
    }
    void displayData(){
        cout<<"\nEmployee details are as below\n";
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<eid<<endl;
        cout<<"Basic Salary: "<<bsal<<endl;
    }
    double netSalary(){
        double it=0.3, da=0.52;
        double gsal= bsal+ (bsal*da);
        nsal=gsal- (gsal*it);
        return nsal;
    }
};

int main(){
    int n;
    cout<<"Enter number of Employees\n";
    cin>>n;
    employee company[n];
}