#include<iostream>
using namespace std;

class student{
    protected:
    string name;
    int usn;
    student(){
        cout<<"Enter student details below\n";
        cout<<"Student name: ";cin>>name;
        cout<<"USN: ";cin>>usn;
    }
    student(string n,int u):name(n),usn(u){}
};

class marks:public student{
    protected:
    int m1,m2,m3;
    double totalMarks;
    public:
    marks(){
        cout<<"Enter 3 subject marks below\n";
        cout<<"Sub1: ";cin>>m1;
        cout<<"Sub2: ";cin>>m2;
        cout<<"Sub3: ";cin>>m3;
        totalMarks=double(m1+m2+m3)/3;
    }
    marks(string n,int u,int m4,int m5,int m6):student(n,u),m1(m4),m2(m5),m3(m6){totalMarks=double(m1+m2+m3)/3;}
};

class sports{
    protected:
    int points;
    sports(){
        char response;
        cout<<"Have you participated in any sports? (y/n)";cin>>response;
        if(response=='N'||response=='n') points=0;
        else{
            cout<<"Enter the points awarded in your sports: ";
            cin>>points;
        }
    }
    sports(int s):points(s){}
};

class result: public marks,public sports{
    public:
    double finalMarks=0;
    result(){}
    result(string n,int u,int m4,int m5,int m6,int s):sports(s),marks(n,u,m4,m5,m6){}
    void resultGenerator(){
        if(totalMarks==double(100))finalMarks=totalMarks;
        else{
            if(points>=9) finalMarks=(0.1*totalMarks)+totalMarks;
            else if(points>=5&&points<9) finalMarks=(0.05*totalMarks)+totalMarks;
            else finalMarks=totalMarks;
        }
        if(finalMarks>100) finalMarks=100;
        cout<<"Your total marks from exam is: "<<totalMarks<<endl;
        cout<<"Your score after adding your sports' points is "<<finalMarks<<" %!!"<<endl;
    }
};

int main(){
    result guna;
    guna.resultGenerator();
}

