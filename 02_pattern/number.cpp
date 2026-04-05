#include<iostream>
using namespace std;

int main()
{
    int n, num=1; 

    cout<<"Enter the number : ";
    cin>>n;
    // cout<<"Enter the number : ";
    // cin>>m;

  for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //cout<<i<<" ";
            //cout<<j<<" ";
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
    return 0;
}