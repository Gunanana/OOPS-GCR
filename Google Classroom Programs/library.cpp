//Develop a class called Library that has data members: Book_Title, Book_id, author and price of the book. Member functions get_data() to accept the data and member function display () to display the book details. Also compare the price of the books and display the book details of the highest price. Define all the member functions outside the class. Use a Static variable to count the number of books in the library and display the same. Write a main() function to create an array of library objects. Accept and display the details for n books.

#include<bits/stdc++.h>
using namespace std;


class library{
    string bt,author;
    int bid,price;
    static int count;
    public:
    static void counter();
    friend void getData(library b[],int x);
    friend void displayData(library b);
    friend void comparePrice(library b[],int x);
};

int library::count;

void library::counter(){
    count++;
    cout<<"This Library has "<<count<<" number of books"<<endl;
}

void getData(library b[],int x){
    for(int i=0;i<x;i++){
        cout<<"Enter book's Title\n";
        cin>>b[i].bt;
        // cout<<"Enter book's id\n";
        // cin>>b[i].bid;
        // cout<<"Enter book's Author's name\n";
        // cin>>b[i].author;
        cout<<"Enter book's price\n";
        cin>>b[i].price;
        //library::counter();
    }
}

void displayData(library b){
    cout<<"Book's name is "<<b.bt<<endl;
    // cout<<"Book's Author's name is "<<b.author<<endl;
    // cout<<"Book's Id is "<<b.bid<<endl;
    cout<<"Book's price is "<<b.price<<" INR"<<endl;
}

void comparePrice(library b[],int x){
    int max=b[0].price;
    library b1;
    for(int i=0;i<x;i++){
        if(max<=b[i].price) {
            max=b[i].price;
            b1=b[i];
        }
    }
    cout<<"The most expensive book's details are printed below\n";
    displayData(b1);
}


int main(){
    int x;
    cout<<"Enter number of books u wanna install into the library\n";
    cin>>x;
    library list[x];
    getData(list,x);
    comparePrice(list,x);
    return 0;
}