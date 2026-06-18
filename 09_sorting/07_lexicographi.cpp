#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 34

/*
    LeetCode 31 : Next Permutation

    Lexicographically Next : Find Pivot → Swap with Next Greater → Reverse Suffix

    Approach :
        1. Find the first decreasing element from the right (pivot).
        2. Find the next greater element than pivot from the right.
        3. Swap them.
        4. Reverse the suffix after the pivot.

    Why reverse?
    - Elements after the pivot are always in descending order.
    - Reversing makes them the smallest possible arrangement,
      giving the immediate next lexicographical permutation.

    Example:
    1 2 3 6 5 4
        ^
      pivot = 3

    Swap with next greater element (4):
    1 2 4 6 5 3

    Reverse suffix:
    1 2 4 3 5 6

    Edge Case:
    - If no pivot exists (array is completely descending),
      reverse the entire array to get the smallest permutation.

    Time Complexity : O(n)
    Space Complexity : O(1)
*/

void nextPermutation(vector<int>& A){     //TC = O(n)   SC = 0(1)

    int pivot = -1, n = A.size();
    
    for(int i = n-2; i>=0; i--){

        if(A[i] < A[i+1]){
            pivot = i;
            break;
        }
    }

    //If A in Decending so convert in Ascending -> No smallest no exist
    if(pivot == -1){
        reverse(A.begin(), A.end()); //in place changes
        return;
    }

    //next largest element
    for(int i=n-1; i>pivot; i--){

        if(A[i] > A[pivot]){
            swap(A[i], A[pivot]);
            break;
        }
    }

    //Reverse [piv+1 to n-1]
    //reverse(A.begin() + pivot+1, A.end());

    int i = pivot+1, j = n-1;
    while(i <= j){
        swap(A[i++], A[j--]);
    }

    //For this we also use STL function
    
    // next_permutation(A.begin(), A.end());
}

int main(){

    vector<int> A = {1,2,3,6,5,4};
   // int n = 6;

    nextPermutation(A);
    
    for(int x : A){
        cout<<x<<" ";
    }

    return 0;
}