#include<iostream>
using namespace std;

int main()
{
    int n=4, m=3;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
    
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }

        // for(int j=1;j<=n-i;j++)
        // {
        //     cout<<" ";
        // }
    

        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }      

       for(int j=1;j<=i;j++)
       {
        cout<<"*";
       }
       cout<<endl;
    }

for(int i=1;i<=m;i++)
    {
       for(int j=1;j<=m-i+1;j++)
       {
        cout<<"*";
       }
       
        for(int j=1;j<=i;j++)
        {
            cout<<" ";
        }

       for(int j=1;j<=i;j++)
       {
        cout<<" ";
       }

       for(int j=1;j<=m-i+1;j++)
       {
        cout<<"*";
       }
       cout<<endl;
    }
   
    return 0;
}