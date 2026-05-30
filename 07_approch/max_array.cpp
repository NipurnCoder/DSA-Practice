#include<iostream>
#include<climits>
using namespace std;

//Revision Day 15

/*
    Problem : Maximum Subarray Sum

    Approach : Brute Force

    Generate all possible subarrays.
    Keep adding elements to get current subarray sum.
    Track the maximum sum found.

    Time Complexity : O(n^2)
    Space Complexity : O(1)

*/

int max_arr(int arr[],int sz){

    //initialize with minimum
    int maxSum= INT_MIN;

    for(int st=0; st<sz; st++){
        int sum=0;

        for(int end=st; end<sz; end++){
            sum+=arr[end];
            maxSum = max(sum,maxSum);
        }
    }
    cout<<"Maximum sum of Array is : "<<maxSum<<endl;
}

int main(){

    int arr[] = {3,-4,5,4,-1,7,-8};
    int sz = sizeof(arr)/sizeof(int);
    
    cout<<"Array is : ";

    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    max_arr(arr,sz);

    return 0;
}