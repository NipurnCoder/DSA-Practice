#include<iostream>
using namespace std;

int prime(int a)
{
    // int a;
    // cout<<"Enter your number : ";
    // cin>>a;

    if(a < 2){
        cout<<a<<" is not a prime";
    }
    
    bool isprime=true;

    for(int i=2; i*i<=a; i++)
    {
        if(a % i ==0)
        {
            isprime=false;
            break;
        }
    }

    if(isprime)
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
    prime(1);
    cout<<endl;
    prime(13);
}