#include<iostream>
using namespace std;

int main()
{
    float s, p, r, t ;

    cout<<"Enter Principle amount ₹ : ";
    cin>>p;

    cout <<"Enter Rate of interest(%) : ";
    cin>>r;

    cout<<"Enter time period : ";
    cin>>t;

    s=(p*r*t)/100;

    cout<<"Simple Interest is : "<<s<<endl;

    return 0;
}

