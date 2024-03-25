//Develop a C++ program to illustrate the use of a friend function to print the employee details who have worked for more hours in a day. For this program use Class Time and Class Employee which you have previously created for other programs. Combine the two programs to demonstrate the friend function.
#include<bits/stdc++.h>
using namespace std;

class timer{
    protected:
    int h,m,h1,m1,th,tm,status;
    int entime,extime,ttime;
    public:
    void signIn(int i){
        cout<<"\nEnter Employee no."<<i<<"'s Entry time in 24 hour system"<<endl;
        cout<<"Enter hour"<<endl;
        cin>>h;
        cout<<"Enter minute\n";
        cin>>m;
    }
    void signOut(int i){
        cout<<"\nEnter Employee no."<<i<<"'s Exit time in 24 hour system"<<endl;
        cout<<"Enter hour"<<endl;
        cin>>h1;
        cout<<"Enter minute\n";
        cin>>m1;
    }
    int calculator(){
        entime=h*60+m;
        extime=h1*60+m1;
        if(extime<entime) extime=extime+1440;
        ttime=extime-entime;
        th=floor(ttime/60);
        tm=(ttime-th*60);
        return ttime;
    }
    void calculate(){
        entime=h*60+m;
        extime=h1*60+m1;
        if(extime<entime) extime=extime+1440;
        ttime=extime-entime;
        th=floor(ttime/60);
        tm=(ttime-th*60);
        cout<<"Total time worked is "<<th<<" hours "<<tm<<" minutes\n";
    }
    
};

class employee: public timer{
    int eid,key=1;
    static int count;
    friend void compareTime(employee BMSCE[],int num);
    public:
    string name;
    employee(){
        count++;
        start(count);
    }
    void start(int i){
        while(key){
            cout<<"\nEnter Employee No."<<i<<"'s details below\n";
            cout<<"(0) Enter Name\n";
            cout<<"(1) Entering Office\n";
            cout<<"(2) Exiting Office\n";
            cout<<"(3) Calculate my work time\n";
            cout<<"(4) Exit object No."<<i<<endl;
            cin>>status;
            switch (status){
                case 0:
                getData(i);
                break;
                case 1:
                signIn(i);
                break;
                case 2:
                signOut(i);
                break;
                case 3:
                calculate();
                break;
                case 4:
                key=0;
            }
        }
        
    }
    void getData(int i){
        cout<<"\nEnter Employee no. "<<i<<" name\n";
        cin>>name;
    }

};

int employee::count;

//friend function 1
void compareTime(employee BMSCE[],int num){
    int employee_index,max=0;
    for(int i=0;i<num;i++){
        if(BMSCE[i].calculator()>max) {
            max=BMSCE[i].calculator();
            employee_index=i;
        }
    }
    cout<<BMSCE[employee_index].name<<" has put in the most number of hours in work!!\n";
    BMSCE[employee_index].calculate();
}

int main(){
    //string max_name="no one";
    int num=0;
    cout<<"Enter the number of Employees in your Institution\n";
    cin>>num;
    employee BMSCE[num];
    //num=objectArrayMaker(BMSCE);
    compareTime(BMSCE,num);
    return 0;
}