#include<iostream>
using namespace std;

//Revision Day 48

/*
    LeetCode 74, 240 : Search in a 2D Matrix and it's 2nd part

    Approach :

        Traverse the matrix using nested loops.
        Compare each element with the target value.

        If the target is found:
            - Store its coordinates using pair<int,int>
            - Print its position
            - Return true

        If the entire matrix is traversed and the target
        is not found, return false.

    Time Complexity = O(row × col)
    Space Complexity = O(1)

*/

bool isFound(int matrix[][3], int row, int col, int tar){

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){

            if(matrix[i][j] == tar){

                pair<int,int>p = {i+1, j+1};
                cout<<"Coordinate(r,c) "<<p.first<<","<<p.second<<endl;

                return true;
            }
        }
    }

    return false;
}

int main(){

    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row = 3;
    int col = 3;

    cout<<endl<<"The matrix is "<<endl;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int t;
    cout<<"Enter Target - ";
    cin>>t;

    cout<<isFound(matrix, row, col , t)<<endl;

    // cout<<"Enter the elments "<<endl;
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cin>>matrix[i][j];
    //     }
    // }

    return 0;
}