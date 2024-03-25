//Create a class Time with members to store hours and minutes, members functions to store and retrieve values and any other appropriate functions for calculation. Given sign-in time and sign-out time, the program has to calculate the total number of hours and minutes an employee has worked and print the time format.
#include <iostream>
#include <cmath>

using namespace std;

class timer{
    int h,m,h1,m1,th,tm,status;
    int entime,extime,ttime;
    public:
    void start(){
        while(1){
            cout<<"Enter your status\n";
            cout<<"(1) Entering Office\n";
            cout<<"(2) Exiting Office\n";
            cout<<"(3) Calculate my work time\n";
            cout<<"(4) Exit program\n";
            cin>>status;
            switch (status){
                case 1:
                signIn();
                break;
                case 2:
                signOut();
                break;
                case 3:
                calculate();
                break;
                case 4:
                exit(0);
            }
        }
        
    }
    void signIn(){
        cout<<"Enter your entry time in 24 hour"<<endl;
        cout<<"Enter hour time"<<endl;
        cin>>h;
        cout<<"Enter minute time\n";
        cin>>m;
    }
    void signOut(){
        cout<<"Enter your exit time in 24 hour"<<endl;
        cout<<"Enter hour time"<<endl;
        cin>>h1;
        cout<<"Enter minute time\n";
        cin>>m1;
    }
    void calculate(){
        entime=h*60+m;
        extime=h1*60+m1;
        if(extime<entime){
            extime=extime+1440;
        }
        ttime=extime-entime;
        th=floor(ttime/60);
        tm=(ttime-th*60);
        cout<<"Total time worked is "<<th<<" hours "<<tm<<" minutes\n";
        }
    
};

int main(){
    timer gunanka;
    gunanka.start();
    return 0;
}
