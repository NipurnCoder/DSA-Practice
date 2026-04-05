#include<iostream>
using namespace std;

int main()
{
    //int n=5, m=5;

    int n, m=n;
    cout<<"Enter the number : ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //cout<<i<<" ";
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}