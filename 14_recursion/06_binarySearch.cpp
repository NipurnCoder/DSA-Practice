#include<iostream>
#include<vector>
using namespace std;

//Revision Day 68

/*
    LeetCode 278 : First Bad Version
             374 : Guess Number Higher or Lower   

    Topic: Recursion + Binary Search
    Problem: Search in a Sorted Array

    Time Complexity: O(log n)
    Space Complexity: O(log n) (recursive call stack)
*/

int isFound(vector<int>& arr, int tar, int st, int end){

    if(st <= end){
        int mid = st + (end - st)/2;

        if(arr[mid] == tar){
            return mid;
        }
        else if(arr[mid] <= tar){
            return isFound(arr, tar, mid+1, end);
        }
        else{
            return isFound(arr, tar, st, mid-1);
        }
    }

    return -1;
}

int main(){

    vector<int> arr = {-1,0,3,5,9,12};
    cout<<isFound(arr, 9, 0, arr.size()-1);
    
    return 0;
}
