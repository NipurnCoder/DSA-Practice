#include<iostream>
#include<vector>
using namespace std;

// Revision Day 52 [07/07/26]

/* 
    LeetCode 240 done
    LeetCode 378 : Kth Smallest Element in The Sorted Matrix
    
    Search in a Sorted Matrix (Row-wise & Column-wise Sorted)

    Approach:
    - Start from the top-right corner.
    - If current element == target → found.
    - If current element > target → move left.
    - If current element < target → move down.
    - Eliminate one row or one column in every step.

    Time Complexity : O(rows + cols)
    Space Complexity: O(1)

    Pattern:
    Matrix + Greedy Elimination

    Remember:
    Top-right  -> Left if bigger
                -> Down if smaller

    Bottom-left -> Up if bigger
                -> Right if smaller
*/

bool search(vector<vector<int>>&mat, int target){

    int r = mat.size(), c = mat[0].size();
    int st = 0, end = c-1;

    while(st < r && end >= 0){

        if(target == mat[st][end]){
            return true;
        } 
        else if(target < mat[st][end]){
            end--;
        } 
        else {
            st++;
        }
    }

    return false;
}

int main(){

    vector<vector<int>>mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout<<search(mat, 10)<<endl;

    return 0;
}