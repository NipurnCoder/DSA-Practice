#include<iostream>
using namespace std;

// Revise this approach today

void reverse(int arr[], int size) //arr of size 6 or arr[6]
{
    int start=0, end=size-1; //Starting Pointer, Ending Pointer in Array 

    while(start<end)
    {
        swap(arr[start],arr[end]); //use Swap Function to reverse it's elements
        start++;    //update start pointer
        end--;      //same for end pointer
    }
}

int main()
{
    int arr[] = {4,5,6,7,8,9}; //elements in array
    int size=6;
    cout<<"Reverse array - "<<endl;

    reverse(arr,size); //Funtion Call
    
        for(int i=0;i<size;i++) //loop to print Array's elements in reverse order
        {
            cout<<arr[i]<<" ";
        }
    
    return 0;
}