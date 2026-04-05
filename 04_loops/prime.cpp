#include<iostream>
using namespace std;

int main()
{
    int n, i=2;
    bool isprime = true;

    cout<<"Enter your number : ";
    cin>>n;

    // for(i;i*i<=n;i++){          //root is best for find prime number
    //     if(n%i==0){
    //         isprime = false;
    //         break;
    //     }
    // }

    // if(isprime == true){
    //     cout<<"It is Prime number ";
    // }
    // else{
    //     cout<<"It is Non Prime number ";
    // }

    while(i<=(n-1))
    {
        if(n%i==0)
        {
            cout<<"It is NOT PRIME ";
            break;
        }

        else
        {
            i+=1;
        }
         cout<<"It is PRIME ";
    }
    
return 0; 
}