#include<iostream>
#include<vector>
using namespace std;

//Revision Day 33 [17/6/26]

/*
    LeetCode 912, 88 :  Merge Sorted Array 

    Merge Sorted Array

    Approach :
          
        Use three pointers:
        i -> last valid element of A
        j -> last element of B
        idx -> last position of A

        Compare from the back and place the larger element.
        If B still has elements left, copy them into A.

        Time Complexity = O(m+n)
        Space Complexity = O(1)

*/

void merge(vector<int> &A, int m, vector<int> &B, int n){  //O(1) SC    O(m+n) TC

    int idx = m+n-1, i = m-1, j = n-1;

    while(i >= 0 && j >= 0){

        if(A[i] >= B[j]){
            A[idx--] = A[i--]; //A[idx] = b[j];    
        } else{                //idx--; j--;
            A[idx--] = B[j--];
        }
    }

    //if j remains
    while(j >= 0){
        A[idx--] = B[j--];
    }
}

int main(){

    vector<int> A = {1,2,3,0,0,0};
    int m = 3;

    vector<int> B = {2,5,6};
    int n = 3;

    merge(A,m, B,n);

    for(int i : A){
        cout<<i<<" ";
    }

    return 0;
}