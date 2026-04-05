#include<iostream>
using namespace std;

int main()
{
    int n=4, m=1;

    //---------------------------------------
    // for(int i=1;i<=n;i++)     #1 12 123...
    // {
    //     for (int j=1;j<=i;j++)

    //---------------------------------------
    // for(int i=1;i<=n;i++)       //# Floyd's triangle  1 23 456...
    // {
    //     for(int j=1;j<=i;j++) 

    //---------------------------------------
    // for(int i=0;i<n;i++)     //# Reverse triangle 1 21 321...
    // {
    //     for(int j=i+1;j>0;j--)       
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
           cout<<" ";
        }
        for(int k=0;k<(n-i);k++)
        {
            cout<<(i+1)<<" ";
          
        }
         cout<<endl;
    }

    
    //     {
    //         //cout<<j<<" ";
    //         // cout<<m<<" ";
    //         // m++;
            
    //     }
    //     cout<<endl;
    // }
  return 0;  
}