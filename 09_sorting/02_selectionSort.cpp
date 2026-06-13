#include<iostream>
using namespace std;

//Revision Day 29

/*
    Selection Sort

    Idea:
    - Find the smallest element from the unsorted part of the array.
    - Swap it with the first element of the unsorted part.
    - Repeat until the array becomes sorted.

    Example:
    {2, 5, 1, 3, 4}

    Pass 1: smallest = 1  -> {1, 5, 2, 3, 4}
    Pass 2: smallest = 2  -> {1, 2, 5, 3, 4}
    Pass 3: smallest = 3  -> {1, 2, 3, 5, 4}
    Pass 4: smallest = 4  -> {1, 2, 3, 4, 5}

    Time Complexity:
    - Best Case    : O(n²)
    - Average Case : O(n²)
    - Worst Case   : O(n²)

    Space Complexity:
    - O(1)

    Notes:
    - In each pass, find the index of the smallest element
      (smallestIdx) and swap it with the current position.
    - Performs at most (n - 1) swaps.
    
    - Not a stable sorting algorithm.
*/

void selectionSort(int arr[], int n){ //O(n^2)

    //let small Idx i
    for(int i=0; i<n-1; i++){
        int smallestIdx = i;

        for(int j=i+1; j<n; j++){

            //but j is the smallest so swap
            if(arr[j] < arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n = 5;
    int arr[] = {2,5,1,3,4};

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}