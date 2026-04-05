#include<iostream>
using namespace std;

void changeA(int a){ //change by value
    a = 20;
}

void changeB(int* ptr){ //change by refrence
    *ptr = 600;
}

void changeC(int &d){
    d = 777;
}

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
