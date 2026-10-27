#include<iostream>
using namespace std;

int dec_bin(int n)
{
    int ans=0, pow=1;
    while(n>0)
    {
        int rem=n%2; // 6%2=0, 3%2=1, 1%2=1
        n=n/2; // 6/2=3, 3/2=1, 1/2=0

        ans+=(rem*pow); // 0*1=0, 1*10=10, 1*100=100
        pow*=10; // 1*10=10, 10*10=100, 100*10=1000
    }

    return ans; //0 + 10 + 100 = 110->6
}

int main()
{
    cout<<dec_bin(6)<<endl;

    cout<<1%2;
}