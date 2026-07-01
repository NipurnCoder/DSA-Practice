#include<iostream>
using namespace std;

//Revision Day 47

/*
    LeetCode 566 : Reshape the Matrix
    
    Topic: 2D Arrays in C++

    Concepts Covered:
        1. Declaring a 2D array
        2. Taking matrix input using nested loops
        3. Traversing rows and columns
        4. Printing a matrix
        5. Understanding row-major order

    Time Complexity:
        Input  : O(row × col)
        Output : O(row × col)

    Space Complexity:
        O(row × col)
        
*/

int main(){
    // int arr[5] = {2,4,3,5,6};
    // int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    int matrix[4][3];
    int row = 4;
    int col = 3;

    cout<<"Enter the elements -"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"The matrix is -"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<matrix[3][3];
    return 0;
}  