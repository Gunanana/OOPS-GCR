/*Array of objects: Develop a C++ program to demonstrate an array of objects in class Student. Create appropriate member variables and functions to read and display students’ USN and marks of six courses in three tests. Also calculate the average marks for each course taking best two of three. Test the program for N students.*/

#include<iostream>
#include<iomanip>
using namespace std;

class student{
    int marks[3][3]; //subjects rows, exams or attempts as columns
    int usn;
    int avg[3];
    public:
    student(){
        setData();
        displayData();
        bOTwo();
    }
    void setData(){
        cout<<"\nEnter student's USN: ";cin>>usn;
        cout<<"Enter your marks below";
        for(int i=0;i<3;i++){
            cout<<"\nEnter Sub "<<i+1<<"'s all 3 marks below"<<endl;
            for(int j=0;j<3;j++){
                cin>>marks[i][j];
            }
        }
    }
    void displayData(){
        cout<<"\nStudent Details\n";
        cout<<"USN: "<<usn<<endl;
        cout<<setw(13)<<"MARKS"<<endl;
        for(int i=0;i<3;i++){
            cout<<"SUB "<<i+1<<": ";
            for(int j=0;j<3;j++){
                cout<<setw(4)<<marks[i][j];
            }
            cout<<endl;
        }
    }
    void bOTwo(){
        //instead of finding best of two, find the minimum of three and subtract it from total sum
        //initialise the average mat to 0 first
        for(int i=0;i<3;i++) avg[i]=0;
        //add all 3 tests' marks and store in avg matrix
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                avg[i]=avg[i]+marks[i][j];
            }
        }
        //subtract the minimum test's marks and also divide by 2 to get the avg
        for(int i=0;i<3;i++) {
            avg[i]=avg[i]-min(marks[i][0],min(marks[i][1],marks[i][2]));
            avg[i]=avg[i]/2;
        }
        //display
        cout<<"\nAVERAGE MARKS"<<endl;
        for(int i=0;i<3;i++){
            cout<<"SUB "<<i+1<<": "<<avg[i]<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter number of students in your school: "; cin>>n;
    student school[n];
    return 0;
}