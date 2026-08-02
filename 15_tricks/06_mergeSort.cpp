#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 79

/*
    LeetCode 912 : Sort an Array
             148 : Sort List

    Topic      : Merge Sort (Divide & Conquer)
    Algorithm  : Recursively divide the array into halves,
                    then merge the sorted halves.

    Time       : O(n log n) [Best, Average, Worst]
    Space      : O(n) (Temporary array used during merge)
    Stable     : Yes
    In-Place   : No
    
    Key Points:
    1. Divide array until each subarray has one element.
    2. Merge two sorted subarrays using two pointers.
    3. Use mid = st + (end - st) / 2 to avoid overflow.
    4. Merge operation takes O(n).
    5. Total recursion depth is O(log n).
    
    Pattern:
    Divide -> Sort Left -> Sort Right -> Merge
*/

void merge(vector<int>& arr, int st, int mid, int end){  //tc = O(nlogn)

    vector<int> temp; //sc = O(n)
    int i = st, j = mid + 1;

    while(i <= mid && j <= end){

        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } 
        else{ 
            temp.push_back(arr[j]);
            j++;
        }
    }

    //After ended one of them

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0; idx<temp.size(); idx++){
        arr[idx + st] = temp[idx];
    }    
}

void mergeSort(vector<int>& arr, int st, int end){

    if(st < end){

        int mid = st + (end-st)/2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, st, mid, end);
    }
}

int main(){

    vector<int> arr = {12,31,35,8,32,17};
    mergeSort(arr, 0, arr.size()-1);

    for(auto val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}