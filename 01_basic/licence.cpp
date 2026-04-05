#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Enter your age :";
    cin>>a;

    if(a<=18)
    {
        cout<<"You are eligible for licence"<<endl;
    }

    else
    {
        cout<<"You are NOT eligible for licence";
    }
return 0;

}