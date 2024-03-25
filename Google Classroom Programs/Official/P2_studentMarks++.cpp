//Array of objects: Develop a C++ program to demonstrate an array of objects in class Student. Create appropriate member variables and functions to read and display students� USN and marks of six courses in three tests. Also calculate the average marks for each course taking best two of three. Test the program for N students.

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class student{
    string name;
    int usn,subCounter,examCounter;
    int marks[100][100];
    int bestOfTwo[2][100];
    int avg[100];
    // string subjects[6]={"Phy","USP", "DLD","OOP", "DSA","INC"};
    static int studentCounter;
    public:
    student();
    void getData();
    void getMarks();
    void displayData();
    void bestOfTwoAverage();
};

int student::studentCounter;

student::student(){
    studentCounter++;
    getData();
    getMarks();
    bestOfTwoAverage();
    displayData();
}

void student:: getData(){
    cout<<"\nEnter student no."<<studentCounter<<"'s USN: "; cin>>usn;
    cout<<"Enter their name: "; cin>>name;
    cout<<"Enter number of CIE's this student has attempted (min 3): "; cin>>examCounter;
    cout<<"Enter number of subjects: "; cin>>subCounter;
}

void student:: getMarks(){
    for(int i=1;i<=examCounter;i++){
        cout<<"Enter student no."<<studentCounter<<"'s CIE "<<i<<" marks below\n";
        for(int j=0;j<subCounter;j++){
            cout<<"Sub"<<j+1<<": "; 
            cin>>marks[i-1][j];
        }
    }
}

void student::bestOfTwoAverage(){
    //initialise the best of two array(2*subCounter)
    for(int j=0;j<subCounter;j++){
        int small=INT_MAX;
        int smallIndex;
        int index=0;
        for(int i=0;i<examCounter;i++){
            if(small>=marks[i][j]){
                small=marks[i][j];
                smallIndex=i;
            }
        }
        for(int i=0;i<examCounter;i++){
            if(i==smallIndex) continue;
            else bestOfTwo[index++][j]=marks[i][j];
        }
    }
    //initialise the final average array by the bo2 array
    for(int j=0;j<subCounter;j++){
        avg[j]=0;
        for(int i=0;i<2;i++){
            avg[j]=avg[j]+bestOfTwo[i][j];
        }
    }
    for(int j=0;j<subCounter;j++) avg[j]=ceil(float(avg[j])/2); 
    
}

void student::displayData(){
    cout<<"\nStudent Name: "<<name<<endl;
    int i=0;
    cout<<"       ";
    for(int i=0;i<subCounter;i++) cout<<"Sub"<<i+1<<" ";
    cout<<endl;
    for(int i=0;i<examCounter;i++){
        cout<<"CIE "<<i+1<<": ";
        for(int j=0;j<subCounter;j++){
            cout<<setw(4)<<marks[i][j]<<" ";
        }
        cout<<endl;
    }
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<subCounter;j++) cout<<bestOfTwo[i][j];
    //     cout<<endl;
    // }

    cout<<"\nFinal marks after averaging their best of 2 subjects (rounded off to next integer):\n";
    for(int i=0;i<2;i++){
        if(i==0) {
            cout<<" ";
            for(int j=0;j<subCounter;j++){
                cout<<"Sub"<<j+1<<" ";
                if(j==subCounter-1) cout<<endl;
            }
        }
        else for(int j=0;j<subCounter;j++)cout<<setw(4)<<avg[j]<<" ";
        cout<<endl;
    }
}

int main(){
    int number;
    cout<<"Enter number of students: ";cin>>number;
    student students[number];
    return 0;
}
