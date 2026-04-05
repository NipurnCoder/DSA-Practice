#include<iostream>
using namespace std;

int main()
{
    int n=4;
    // char ch='A';

    for(int i=0;i<=n;i++)
    {
        
        for(int j=1;j<=n-i+1;j++)
        {
            cout<<" ";
        }

        for(int j=1;j<=i+1;j++)
        {
             cout<<j;
             //cout<<ch;
             //ch=ch+1;
        }

        for(int j=i;j>=1;j--)
        {
             cout<<j;
             //cout<<ch;
             //ch=ch+1;
        }

        cout<<endl;
       
    }
    return 0;
}