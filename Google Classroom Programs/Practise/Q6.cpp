/*Operator Overloading: Develop a C++ program to create a class called MATRIX using a two-dimensional array of integers. Illustrate == operator overloading which checks the compatibility of two matrices M1 and M2 for addition and subtraction. Find the sum and difference of matrices by overloading the operators + and – respectively. Display the results (sum matrix M3 and difference matrix M4).*/

#include<iostream>
using namespace std;

class matrix{
    int r, c;
    int **mat;
    public:
    matrix(int row, int col): r(row),c(col){
        mat= new int*[r];
        for(int i=0;i<r;i++) mat[i]=new int[c];
    }
    friend bool operator==(const matrix &m1, const matrix &m2){
        for(int i=0;i<m1.r;i++) for(int j=0;j<m1.c;j++) if(m1.mat[i][j]!=m2.mat[i][j]) return false;
        return true;
    }
    friend matrix &operator+(const matrix &m1, const matrix &m2){
        matrix temp(m1.r,m1.c);
        for(int i=0;i<m1.r;i++) for(int j=0;j<m1.c;j++) temp.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
        return temp;
    }
    friend matrix &operator-(const matrix &m1, const matrix &m2){
        matrix temp(m1.r,m1.c);
        for(int i=0;i<m1.r;i++) for(int j=0;j<m1.c;j++) temp.mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
        return temp;
    }
};