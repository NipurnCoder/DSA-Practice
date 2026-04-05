#include<iostream>
using namespace std;

int main()
{
 int a, i=1, evensum=0, oddsum=0;
     cout<<"Enter the number : ";
     cin>>a;


    while(i<=a)
    {

        if(i%2==0)
        {
         cout<<i<<endl;
         evensum+=i;
        }
        // else if(i%2!=0)
        // {
        //     cout<<i<<endl;
        //     oddsum+=i;
        // }

        i++;     
    }    
    cout<<"Sum of even numbers is :"<<evensum<<endl;
    return 0;

}    