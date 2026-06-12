#include<iostream>
using namespace std;

//Revision Day 28 [12/6/26]

/*

    Bubble Sort

    Idea:
    - Compare adjacent elements.
    - Swap if they are in the wrong order.
    - After each pass, the largest unsorted element
      moves to its correct position at the end.

    Optimization:
    - If no swaps occur in a pass, the array is already sorted.
    - Stop early using the isSwap flag.

    Time Complexity:
    - Best Case    : O(n)
    - Average Case : O(n²)
    - Worst Case   : O(n²)

    Space Complexity:
    - O(1)

    Stable Sort: Yes
    In-place Sort: Yes

*/

void bubbleSort(int arr[], int n){ //O(n^2)

    for(int i=0; i<n-1; i++){
        bool isSwap = false;    //optimised

        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){

                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

void printArray(int arr[],int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void inputArray(){
    //If user want to use it's own created Arr
}

int main (){
    int n = 5;
    int arr[] = {2,4,5,1,3};

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}