#include<iostream>
#include<vector>
using namespace std;

//Revision Day 51

/*
    LeetCode 34 : Find First and Last Position of Element in Sorted Array

    Concept:
    - Binary Search on Rows
    - Identify the row in which target can exist
    - Apply Binary Search within that row
    - Matrix is treated as a collection of sorted rows

    Approach:
    1. Perform binary search over rows.
    2. Check whether target lies between
       mat[midRow][0] and mat[midRow][n-1].
    3. If yes, binary search that row.
    4. If target is greater than the last element
       of the current row, move downward.
    5. Otherwise, move upward.

    Time Complexity : O(log m + log n)
    Space Complexity: O(1)
*/

bool searchEleRow (vector<vector<int>>&mat, int target, int row){

    int n = mat[0].size();
    int st = 0, end = n-1;

    while(st <= end){
        
        int mid = st + (end-st)/2;

        if(target == mat[row][mid]){
            return true;
        } 
        else if (target > mat[row][mid]){
            st = mid+1;
        } 
        else {
            end = mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>&mat, int target){

    int m = mat.size(), n = mat[0].size(); //m = row, n = columns
    int stRow = 0, endRow = m-1;

    while(stRow <= endRow){

        int midRow = stRow + (endRow - stRow)/2;

        if(target >= mat[midRow][0] && 
            target <= mat[midRow][n-1]){

            return searchEleRow(mat, target, midRow);
        } 
        else if(target > mat[midRow][n-1]){
            stRow = midRow+1;
        } 
        else {
            endRow = midRow-1;
        }
    }
    return false;
}

int main(){

    vector<vector<int>>mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(mat, 34)<<endl;
    
    return 0;
}