#include<iostream>
#include<climits>
using namespace std;

//Revision Day 12 

/*
    LeetCode-53 : Maximum Subarray

    Approach : Kadanes Algorithm

    Finds maximum sum of a contiguous subarray in an array
    Time = O(n)
    Space = O(1)
    If cost goes negative start fresh
*/

int kadanes(int arr[], int sz)
{
    //Initialize cost and for compare use maxs
    int cs=0, maxs=INT_MIN;

    //Travels all Val of array
    for(int i=0;i<sz;i++)
    {
        //Add the cost
        cs+=arr[i];
        //Select maximum cost
        maxs=max(cs,maxs);

        //Handle negative costs
        if(cs<0)
        {
            cs=0;
        }
    }
    // cout<<maxs<<endl;
    return maxs;
}

int main()
{
    int arr[]={3,-4,5,4,-1,7,-8};
    int sz=7;

    //kadanes(arr,sz);
    cout<<kadanes(arr, sz)<<endl;

    return 0;
}