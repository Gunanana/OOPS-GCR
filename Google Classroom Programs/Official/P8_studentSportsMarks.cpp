/*class student (name,usn)
class marks derives student (marks m1,m2,m3)
class sports(points)
class result derives marks and sports (final marks)*/

#include<iostream>
#include<string.h>
using namespace std;

class student{
protected:
    string name;
    int usn;
public:
    student(){}
    student(string n, int u):name(n),usn(u){}
};

class marks: public student{
protected:
    double m1,m2,m3,average;
public:
    marks(){}
    marks(string n, int u, int ma, int mb, int mc): student(n,u),m1(ma),m2(mb),m3(mc){average=(m1+m2+m3)/3;}
};

class sports{
protected:
    int points;
public:
    sports(){}
    sports(int p): points(p){}
};

class result :public marks, public sports{
protected:
    char response;
    double finalMarks;
public:
    result(){}
    result(string n, int u, int ma, int mb, int mc, int p=0):marks(n,u,ma, mb,mc),sports(p){}
    void resultGenerator(){
        if(average==100) finalMarks=100;
        else{
            cout<<"Have you participated in any sports?(y/n)\n";
            cin>>response;
            if(response=='y'){ 
                cout<<"Enter your points\n";
                cin>>points;
                if(points>=8) finalMarks=average+average/10;
                else if(points>=5&&points<8)finalMarks=average+average/5;
                else finalMarks=average;
                if(finalMarks>100) finalMarks=100;
            }
            else{
                finalMarks=average;
            }
        }
        cout<<"Your final marks is "<<finalMarks;
    }
};

int main(){
    result guna("G",2,100,100,70);
    guna.resultGenerator();
}