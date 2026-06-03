#include<iostream>
using namespace std;

//Revision Day 20

/*
    Concept: Passing Variables to Functions

    Time - O(1)
    Space - O(1)

*/

//pass by value
void changeA(int a){ 
    a = 20;
}

//pass by pointer
void changeB(int* ptr){ 
    *ptr = 600;
}

//pass by reference (alias)
void changeC(int &d){
    d = 777;
}

//Pointer Increment and Decrement
void incDec(){
    int a = 1;
    int *p = &a;

    cout<<p<<endl;
    p++;
    cout<<p<<endl;
    p--;
    cout<<p<<endl;
} 

int main(){

    int a = 10;
    changeA(a);
    cout<<"Changed value : "<<a<<endl;

    int b = 500;
    changeB(&b);
    cout<<"Changed by pointer : "<<b<<endl;

    int c = 999;
    changeC(c);
    cout<<"change by alias : "<<c<<endl;

    incDec();
    return 0;
}
