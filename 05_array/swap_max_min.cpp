#include<iostream>
#include<climits> 
//climits to use max and min
using namespace std;

//Revise todat 19/05


//Funtion 
int swap_min_max(int arr[], int size) 
{
    //initialization with min, max
    int a=INT_MIN, num; 
    int b=INT_MAX, min;

    int num_index=-1, min_index=-1;

    for(int i=0;i<size;i++)
    {
        //always true
        if(arr[i]>a) 
        {
            a=arr[i];
            num=arr[i];
            num_index=i;
            //max found
        }

        if(arr[i]<b)
        {
            b=arr[i];
            min=arr[i];
            min_index=i;
            //min found
        }
    }

    cout<<"Max number : "<<num<<endl;
    cout<<"Min number : "<<min<<endl;

    //swaping with 3 variables
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
    //int arr[]={22,-45,67,-29,87,99,10};
    int arr[]={4,5,-2,1,3,-7};
    int size=6;

    cout<<"Original array "<<endl;

    //print arr
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //function call
    swap_min_max(arr,size);

    return 0;
}