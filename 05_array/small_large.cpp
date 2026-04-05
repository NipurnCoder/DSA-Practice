#include<iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {20, 7, -10, -19, 32};
    int size=5;

    int smallest = INT_MAX ;
    int s_index = -1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]<smallest)
        {
            smallest=arr[i]; 
            s_index = i;
        }
    }
    cout<<"smallest is "<<smallest<<" at index "<<s_index<<endl;
    //smallest=min(arr[i],smallest);

    int largest = INT_MIN;
    int l_index = -1;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>largest)
        {
            largest = arr[i];
            l_index = i;
        }
    }
    cout<<"Largest is "<<largest<<" at index "<<l_index<<endl;
}

