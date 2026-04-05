#include<iostream>
using namespace std;

int rev(int n)
{
    int ans=0, rem;
    
    
       for(;n!=0;n/=10)
        {
            rem=n%10;
            ans=ans*10+rem;

            // rem=n%10;
            // num=(ans+rem);
            // ans=(num*10);
            // n/=10;
            //break;
        }
    return ans;
}

int main ()
{
    cout<<rev(6789)<<endl;
}

