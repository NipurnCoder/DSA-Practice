#include<iostream>
using namespace std;

int main()
{
    int n=3;
    char ch='A';

    for(int i=0;i<n;i++)
    {
        //char ch='A';
        for(int j=1;j<=n;j++)
        {
            cout<<ch;
            ch=ch+1;
        }
        cout<<endl;
    }
    return 0;
}