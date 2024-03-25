//Simple Classes and Objects: Create an EMPLOYEE class with the following members: Employee ID(Integer type), Employee Name, Basic, DA, IT, Net Salary. Member functions: to read the data, to calculate Net Salary and to print data members. Develop C++ program to demonstrate reading N employees information and compute Net Salary of each employee. (Consider Dearness Allowance (DA) = 52% of Basic and Income Tax (IT) = 30% of the gross salary. Net Salary = Basic + DA - IT).

//basic salary is the base. doesnt include anything, just raw
//da is added to basic sal
//gross sal is basic sal plus da for an year
//income tax is calculated on gross sal

#include<iostream>
using namespace std;

class employee{
    float eid,bsal,da,it,nsal,gsal;
    char name[100];
    public:
    void setData(){
        cout<<"Enter Employee id\n";
        cin>>eid;
        cout<<endl;
        cout<<"Enter Employee name\n";
        cin>>name;
        cout<<endl;
        cout<<"Enter your Basic Salary\n";
        cin>>bsal;
        cout<<endl;
    }
    float netSalary(){
        da=0.52*bsal;
        gsal=bsal+da;
        it=0.3*gsal;
        nsal=gsal-it;
        //cout<<"Net Salary is "<<nsal<<endl;
        return nsal;
    }
    void getData(){
        cout<<"Employee id is "<<eid<<endl;
        cout<<"Employee name is "<<name<<endl;
        cout<<"Employee's Net Salary is "<<netSalary()<<endl;
    }

};
int main(){
    employee guna;
    guna.setData();
    guna.getData();
    return 0;
}