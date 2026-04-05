#include<iostream>
using namespace std;

int main()
{
    int a, i=1, evensum=0;
    cout<<"Enter the number : ";
    cin>>a;


    while(i<=a)
    {
        if(i%2==0)
        {
         cout<<i<<endl;
         evensum+=i;
        }
        i++;
    }    

    cout<<"Sum is :"<<evensum<<endl;


    // if(a%2==0)
    // {
    //     cout<<"Your number is EVEN ";
    // }

    // else
    // {
    //     cout<<"Your number is ODD ";
    // }

return 0;
}