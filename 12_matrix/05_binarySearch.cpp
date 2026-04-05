#include<iostream>
#include<vector>
using namespace std;

bool searchEleRow (vector<vector<int>>&mat, int target, int row){
    int n = mat[0].size();
    int st = 0, end = n-1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(target == mat[row][mid]){
            return true;
        } else if (target > mat[row][mid]){
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>&mat, int target){
    int m = mat.size(), n = mat[0].size(); //m = row, n = colmns
    int stRow = 0, endRow = m-1;

    while(stRow <= endRow){
        int midRow = stRow + (endRow - stRow)/2;

        if(target >= mat[midRow][0] && target <= mat[midRow][n-1]){
            return searchEleRow(mat, target, midRow);
        } else if(target >= mat[midRow][n-1]){
            stRow = midRow+1;
        } else {
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