#include<iostream>
#include <climits>
using namespace std;

//Revise Today 18/5

int main()
{
    int arr[] = {20, 7, -10, -19, 32};
    int size=5;

    //Initialize smallest with infinite
    int smallest = INT_MAX ;
    int s_index = -1;

    for(int i=0;i<size;i++)
    {
        //always true 1<infinite
        if(arr[i]<smallest)
        {
            //asign val of i
            smallest=arr[i];
            s_index = i;    //idx
        }
    }

    cout<<"smallest is "<<smallest<<" at index "<<s_index<<endl;
    //smallest=min(arr[i],smallest);

    //Same Initialization for large with 0
    int largest = INT_MIN;
    int l_index = -1;

    for(int i=0;i<size;i++)
    {
        //always true 1>0
        if(arr[i]>largest)
        {
            //assign val of i
            largest = arr[i];
            l_index = i;  //idx
        }
    }

    cout<<"Largest is "<<largest<<" at index "<<l_index<<endl;

    return 0;

}

