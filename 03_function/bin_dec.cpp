#include<iostream>
using namespace std;

int bin_dec(int n)
{
    int ans=0, pow=1;

    while(n>0)
    {
        int rem=n%10;
        ans+=(rem*pow);

        n/=10;
        pow*=2; //update pow of 2
    }
    return ans;
}

int main()
{
    //4,2,1
    cout<<bin_dec(110)<<endl;
}