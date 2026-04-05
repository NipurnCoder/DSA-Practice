#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of Array : ";
    cin>>n;
    int size=n;
    int num[size];

    cout<<"Enter elements of array : ";

    for(int i=0;i<size;i++)
    {
        cin>>num[i];
    }

    cout<<"Array is -- ";

    for(int i=0;i<size;i++)
    {
        cout<<num[i]<<" ";
    }
    
// int size = sizeof(num)/sizeof(int);
//     int num[size];
//      cout<<size;
cout<<endl;
int sz=sizeof(num)/sizeof(int);
cout<<"Size of array is : "<<sz<<endl;



return 0;
}