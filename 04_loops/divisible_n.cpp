#include<iostream>
using namespace std;

int main()
{
    int n, m, sum=0;

    cout<<"Enter the last no. -> ";
    cin>>n;

    cout<<"Enter the no. you want to get divisible factors -> ";
    cin>>m;

    for(int i=1;i<=n;i++)
    {
        if(i%m==0)
        {
         cout<<i<<" ";
         sum+=i;

        }
    }
    cout<<endl<<"The sum is : ";
    cout<<sum;

    return 0;
}