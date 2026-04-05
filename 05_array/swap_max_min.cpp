#include<iostream>
#include<climits>
using namespace std;

int swap_min_max(int arr[], int size)
{
    int a=INT_MIN, num;
    int b=INT_MAX, min;

    int num_index=-1, min_index=-1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>a)
        {
            a=arr[i];
            num=arr[i];
            num_index=i;
        }

        if(arr[i]<b)
        {
            b=arr[i];
            min=arr[i];
            min_index=i;
        }
    }
    cout<<"Max number : "<<num<<endl;
    cout<<"Min number : "<<min<<endl;

    int temp=arr[num_index];
    arr[num_index]=arr[min_index];
    arr[min_index]=temp;

    // cout<<"Numbers are swap ";
    // cout<<arr<<" "<<min<<endl;

    cout<<"After swaping "<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]={22,-45,67,-29,87,99,10};
    int size=7;

    cout<<"Original array "<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    swap_min_max(arr,size);
}