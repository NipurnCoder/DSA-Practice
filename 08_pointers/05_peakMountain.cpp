#include <iostream>
#include <vector>
using namespace std;

//Revision Day 23 [6/6/26]

/*
    LeetCode 162 : Find Peak Element
    1st Approach: Linear Search
    Idea:
    - Traverse the array from index 1 to n-2.
    - Check if the current element is greater than both neighbors.
    - The first element satisfying this condition is the peak.

    Time - O(n)
    Space - O(1)
    

    LeeCode 852 : Peak Index in a Mountain Array
    2nd Appraoch: Binary Search
    Idea:
    - If mid is on the increasing slope, move right.
    - If mid is on the decreasing slope, move left.
    - The point where arr[mid] is greater than both neighbors
      is the peak element.

    Time - O(log n)
    Space - O(1)
*/

int linearSearch (vector<int>& arr){

    int n = arr.size();

    for(int i=1; i<=n-1; i++){
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            return arr[i];
        }
    }
    cout<<endl;
    return -1;
}

int binaryMountain (vector<int>& arr){

    int st=1, end=arr.size()-2;

    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }

        else if(arr[mid-1]<arr[mid]){ //increasing slope
            st=mid+1;  //right
        }

        else {
            end=mid-1;  //left
        }
    }
    return -1;
}

int main (){

    vector<int> arr = {0,3,8,9,5,2};

    for (int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    int ans ;
    ans= linearSearch(arr);

    int binaryAns=binaryMountain(arr);

    cout<<"Peak is : " << ans<<endl;
    cout<<"Peak by Binary search : "<<binaryAns;
    return 0;

}