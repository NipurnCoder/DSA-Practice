#include<iostream>
using namespace std;

int dec_bin(int n)
{
    int ans=0, pow=1;
    while(n>0)
    {
        int rem=n%2;
        n=n/2;

        ans+=(rem*pow);
        pow*=10;
    }

    return ans;
}

int main()
{
    cout<<dec_bin(6)<<endl;
}