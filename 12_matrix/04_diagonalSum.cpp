#include<iostream>
#include<vector>
using namespace std;

//Revision Day 50

/*
    LeetCode 73 : Set Matrix Zeroes
    
    Topic : Diagonal Sum in Matrix + 2D Vector Traversal

    Concepts Covered:
    - 2D Arrays
    - 2D Vectors
    - Primary Diagonal (i == j)
    - Secondary Diagonal (j == n - 1 - i)
    - Avoiding double counting of center element
    - Brute Force vs Optimized Approach

    Approach 1: Brute Force
        Traverse the complete matrix and add elements
        belonging to primary or secondary diagonal.

        Time Complexity  : O(n²)
        Space Complexity : O(1)

    Approach 2: Optimized
        Traverse only once from 0 to n-1 and directly
        access both diagonals.

        Time Complexity  : O(n)
        Space Complexity : O(1)

    Condition:
    if(i != n - 1 - i)
        Prevents counting the middle element twice
        in odd-sized matrices.
*/

int diagonal(int mat[][3], int n){      //O(n*n)

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(i == j){
                sum += mat[i][j];
            }
            else if(j == n-1-i){
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

int optiDiaSum(int mat[][3], int n){    //O(n)

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += mat[i][i];

        if(i != n-1-i){
            sum += mat[i][n-1-i];
        }
    }
    return sum;
}

int main(){

    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 3;

    // 2D vector
    // vector<vector<int>> mat1 = {{11,22,33},{44,55,66},{77,88,99}};
    // // int row = mat1.size();
    // // int col = mat1[int i].size();

    // for(int i=0; i<mat1.size(); i++){
    //     for(int j=0; j<mat1[i].size(); j++){
    //         cout<<mat1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"Sum of Diagonal is : "<<diagonal(mat, n)<<endl;
    cout<<"Optimised Diagonal sum : "<<optiDiaSum(mat, n)<<endl;

    return 0;
}