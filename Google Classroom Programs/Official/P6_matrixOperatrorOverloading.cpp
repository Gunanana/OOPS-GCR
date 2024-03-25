//Operator Overloading: Develop a C++ program to create a class called MATRIX using a two-dimensional array of integers. Illustrate == operator overloading which checks the compatibility of two matrices M1 and M2 for addition and subtraction. Find the sum and difference of matrices by overloading the operators + and – respectively. Display the results (sum matrix M3 and difference matrix M4).

#include<iostream>
#include<stdlib.h>
using namespace std;

class matrix{
    int **mat;
    int columns,rows;
public:
    matrix(int r,int c):rows(r),columns(c){
        mat= new int*[rows];
        for(int i=0;i<rows;i++) mat[i]= new int[columns];
        for(int i=0;i<rows;i++) for(int j=0;j<columns;j++) mat[i][j]=0;
    }
    bool operator==(const matrix &rhs) const{
        for(int i=0;i<rows;i++) for(int j=0;j<columns;j++) if(rhs.mat[i][j]!=mat[i][j]) return false;
        return true;
    }
    matrix operator+(const matrix &rhs) const{
        matrix res(rhs.rows,rhs.columns);
        for(int i=0;i<rows;i++) for(int j=0;j<columns;j++) res.mat[i][j]=mat[i][j]+rhs.mat[i][j];
        return res;
    }
    matrix operator-(const matrix &rhs) const{
        matrix res(rhs.rows,rhs.columns);
        for(int i=0;i<rows;i++) for(int j=0;j<columns;j++) res.mat[i][j]=mat[i][j]-rhs.mat[i][j];
        return res;
    }
    friend ostream &operator<<(ostream& out, const matrix& rhs){
        for(int i=0;i<rhs.rows;i++) {
            for(int j=0;j<rhs.columns;j++) out<<rhs.mat[i][j]<<" ";
            out<<"\n";
        }
        return out;
    }
    friend istream &operator>>(istream& in, const matrix&rhs){
        cout<<"Enter matrix elements row wise\n";
        for(int i=0;i<rhs.rows;i++) for(int j=0;j<rhs.columns;j++) in>>rhs.mat[i][j];
        return in;
    }
};


