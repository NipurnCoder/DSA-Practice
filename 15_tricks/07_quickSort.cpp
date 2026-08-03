#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 80 [03/08/2026]

/*
    LeetCode 215 : Kth Largest Element in an Array

    Topic: Quick Sort (Divide & Conquer)

    Algorithm:
    1. Choose the last element as the pivot.
    2. Place the pivot at its correct sorted position.
    3. Recursively sort the left and right subarrays.

    Partition Scheme:
    - Lomuto Partition

    Time Complexity:
    Best Case    : O(n log n)
    Average Case : O(n log n)
    Worst Case   : O(n²)  (already sorted/reverse sorted when last element is pivot)

    Space Complexity:
    O(log n) Average (recursive stack)
    O(n) Worst Case (highly unbalanced recursion)

    Stable: No
    In-place: Yes
*/    

int partition(vector<int>& arr, int st, int end){  //TC : O(nlogn), worst case : O(n2)
   
    int idx = st-1, pivot = arr[end];              //SC : O(1)

    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int>& arr, int st, int end){

    if(st < end){
        
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx-1); //left
        quickSort(arr, pivIdx+1, end); //right
    }
}

int main(){

    vector<int> arr = {5,2,6,4,1,3};
    quickSort(arr, 0, arr.size()-1);

    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}