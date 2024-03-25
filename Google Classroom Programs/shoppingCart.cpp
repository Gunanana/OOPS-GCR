#include<bits/stdc++.h>
using namespace std;

class shop{
    int inp,q;
    static int i1,i2,i3;
    public:
    void start(){
        while(1){
        cout<<"\nWhat item do u need?\n";
        cout<<"(1) Item 1\n";
        cout<<"(2) Item 2\n";
        cout<<"(2) Item 3\n";
        cout<<"(4) Exit\n";
        cin>>inp;
        cout<<"What quantity of "<<inp<<" do u need?\n";
        cin>>q;
        switch (inp){
            case 1:
            aquire(1,q);
            break;
            case 2:
            aquire(2,q);
            break;
            case 3:
            aquire(3,q);
            break;
            case 4:
            exit(0);
        }
    }


    }
    void aquire(int x, int q){
        if(x==1){
            i1-=q;
            teller(1,q,i1);
        }
        else if(x==2){
            i2-=q;
            teller(2,q,i2);
        }
        else{
            i3-=q;
            teller(3,q,i3);
        }

    }
    void teller(int x, int q,int it){
        cout<<"You have received "<<q<<" of item "<<x<<endl;
        cout<<"Amount left is "<<it<<endl;
    }

};

int shop::i1=100;
int shop::i2=100;
int shop::i3=100;

int main(){
    shop guna;
    guna.start();
}