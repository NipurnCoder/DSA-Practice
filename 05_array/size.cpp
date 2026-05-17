#include<iostream>
using namespace std;

//Revise Today 17/5

int main()
{
    //int n;
    int size;
    cout<<"Enter size of Array : "; //Take input of arr's size
    cin>>size;

    //int size=n;
    int num[size];

    cout<<"Enter elements of array : ";

    for(int i=0;i<size;i++)     //Taking the elements of arr
    {
        cin>>num[i];
    }

    cout<<"Array is -- ";

    for(int i=0;i<size;i++)     //Print the elements
    {
        cout<<num[i]<<" ";
    }
    
// int size = sizeof(num)/sizeof(int);      Calculate size of arr by mathematics
//     int num[size];                       1 int = 4 bytes
//      cout<<size;

cout<<endl;
int sz=sizeof(num)/sizeof(int);

cout<<"Size of array is : "<<sz<<endl;

return 0;
}