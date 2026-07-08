#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//Revision Day 53

/*
    LeetCode:
    - LC 54 : Spiral Matrix
    - LC 59 : Spiral Matrix II

    Topic: Spiral Matrix Traversal

    Concepts Revised:
    - Matrix traversal using four boundaries
    - top, right, bottom, left traversal
    - Updating boundaries after each layer
    - Handling single remaining row/column to avoid duplicates

    - 2D Matrix Traversal
    - Boundary Traversal Technique
    - Four pointers:
        -> srow (starting row)
        -> erow (ending row)
        -> scol (starting column)
        -> ecol (ending column)
    - Layer-by-layer (clockwise) traversal
    - Handling edge cases to avoid duplicate elements
    when only one row or one column remains.

    Time Complexity : O(m × n)
    Space Complexity: O(1) (excluding output vector)
*/

vector<int> spiral(vector<vector<int>>&mat){

    int m = mat.size(), n = mat[0].size();
    int srow = 0, scol = 0, erow = m-1, ecol = n-1;

    vector<int> ans;

    while(srow<=erow && scol<=ecol){
        //top
        for(int i=scol; i<=ecol; i++){
        ans.push_back(mat[srow][i]);
        }

        //right
        for(int i=srow+1; i<=erow; i++){
            ans.push_back(mat[i][ecol]);
        }

        //bottom
        //if(srow < scol){

        for(int i=ecol-1; i>=scol; i--){
            if(srow == erow){
                break;
            }
            ans.push_back(mat[erow][i]);
        }
    
        //left
        //if(ecol < erow){  
        
        for(int i=erow-1; i>=srow+1; i--){
            if(scol == ecol){
                break;
            }
            ans.push_back(mat[i][scol]);
        }
        srow++; erow--; scol++; ecol--;
    }
    //srow++; erow--; scol++; ecol--;
    //cout<<ans<<" ";
    return ans;
}

int main(){

    vector<vector<int>>mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int>res = spiral(mat);

    cout<<"Matrix "<<endl;
    for(auto& row : mat){
        for(int val : row){
            cout<<setw(2)<<setfill('0')<<val<<" ";
        }
        cout<<endl;
    }

    cout<<"The spiral matrix "<<endl;
    for(int x : res){
        cout<<x<<" ";
    }

    return 0;
}