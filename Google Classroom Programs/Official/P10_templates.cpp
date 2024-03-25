/*Templates:
a. Illustrate class templates in a C++ program for the following operations: Adding two arrays, finding the max and min in an array.
b. Develop a C++ program to sort using bubble sort by applying function templates.*/

#include<iostream>
#include <limits>
using namespace std;

template <class t>
class array{
    t *arr;
    int size;
    public:
    array(){}
    array(int s):size(s){
        arr = new t[size];
        for(int i=0;i<size;i++) arr[i]=0;
    }
    void setArr(){
        cout<<"\nEnter array elements below\n";
        for(int i=0;i<size;i++) cin>>arr[i];
        cout<<endl;
    }
    void displayArr(){
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    }
    friend array<t> operator+(const array<t> &arr1, const array<t> &arr2){
        array<t> temparr(arr1.size);
        for(int i=0;i<arr1.size;i++) temparr.arr[i]=arr1.arr[i]+arr2.arr[i];
        return temparr;
    }
    t minValue(){
        t min= arr[0];
        for(int i=0;i<size;i++) if(min>arr[i]) min=arr[i];
        return min;
    }

    t maxValue(){
        t max= arr[0];
        for(int i=0;i<size;i++) if(max<arr[i]) max=arr[i];
        return max;
    }
    friend void bubbleSort(array<t> &arr1){
        for(int i=0;i<arr1.size-1;i++)
            for(int j=0;j<arr1.size-1-i;j++)
                if(arr1.arr[j]>arr1.arr[j+1]) swap(arr1.arr[j],arr1.arr[j+1]);
    }
};

int main(){
    int size;
    cout<<"Enter the size of your array: "; cin>>size;

    array<int> arr1(size);
    arr1.setArr();
    arr1.displayArr();

    array<int> arr2(size);
    arr2.setArr();
    arr2.displayArr();

    //a) ADD
    array<int> arr3(size);
    arr3=arr1+arr2;
    cout<<"\nArray after addition:\n"; 
    arr3.displayArr();

    //MAX & MIN
    cout<<"\nThe minimum element in your array is: "<<arr1.minValue();
    cout<<"\nThe maximum element in your array is: "<<arr1.maxValue()<<endl;

    //b) BUBBLE SORT
    cout<<"\nArray before sorting...\n";
    arr1.displayArr();
    cout<<"\nArray after sorting...\n";
    bubbleSort(arr1);
    arr1.displayArr();
    return 0;
}