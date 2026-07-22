#include<iostream>
#include<vector>
using namespace std;

//Revision Day 67

/*
    Topic: Recursion
    Problem: Check if Array is Sorted

    Time Complexity: O(n)
    Space Complexity: O(n) (recursive call stack)

    ✔ Learned:
    - Base case returns true when the array has 0 or 1 element.
    - Compare the last two elements in each recursive call.
    - If the current pair is sorted, recursively check the remaining elements.
    - The recursion stops immediately if any comparison is false.
    - This approach verifies a non-decreasing order using:
      isSorted(n) = (arr[n-1] >= arr[n-2]) && isSorted(n-1).
*/

bool isSorted(vector<int> &arr, int n){

    //n = arr.size();

    if(n == 0 || n == 1){
        return true;
    }
    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main(){

    vector<int> arr = {1,3,7,7,9};
    cout<<isSorted(arr ,arr.size());

    return 0;
}