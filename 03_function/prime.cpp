#include<iostream>
using namespace std;

int prime(int a)
{
    // int a;
    // cout<<"Enter your number : ";
    // cin>>a;
    bool isprime=true;

    for(int i=2;i<=a;i++)
    {
        if(i%a==0)
        {
            isprime==false;
            break;
        }
    }

    if(isprime==true)
    {
        cout<<a<<" PRIME";
    }
    else
    {
        cout<<a<<" NOT PRIME";
    }
    return 0;
}

int main()
{
    prime(12);
    cout<<endl;
    prime(13);
}