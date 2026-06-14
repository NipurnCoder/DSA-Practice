#include<iostream>
using namespace std;

//Revision Day 30 [14/6/26]

/*
    Insertion Sort

    LeetCode 147 : Insertion Sort List

    Idea : 
    - Divide array into Sorted and Unsorted parts.
    - Pick one element from the unsorted part.
    - Insert it into its correct position in the sorted part.

    Time Complexity:
    - Best Case  : O(n)    (Already Sorted)
    - Average Case: O(n²)
    - Worst Case : O(n²)   (Reverse Sorted)

    Space Complexity:
    - O(1)    

    Stable sorted algorithm
*/

void inserstionSort(int arr[], int n){  //O(n^2)

    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] >= curr){      // <---------Ascending or Decending
            arr[prev + 1] = arr[prev];
            prev--;
        }
        //placed the curr at it's correct position
        arr[prev + 1] = curr;
    }
}

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    // int n;
    // cout<<"Enter size : ";
    // cin>>n;

    // cout<<"Enter the elements : ";
    // int arr[n];

    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // cout<<endl<<"Sorted array : ";

    int n = 5;
    int arr[]= {5, -3, 1, 2, 0};

    inserstionSort(arr, n);
    printArray(arr, n);

    return 0;
}