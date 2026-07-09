#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//Revision Day 54

/*
    Topic: 2D Vectors (Matrix)

    Key Points:
    1. vector<vector<int>> is used to represent a matrix.
    2. matrix.size() -> number of rows.
    3. matrix[0].size() -> number of columns.
    4. Nested loops are used to traverse rows and columns.
    5. setw() sets field width for output formatting.
    6. setfill('0') fills empty spaces with zeros.

    Time Complexity  : O(rows * cols)
    Space Complexity : O(1)
    
*/

int main(){

    vector<vector<int>> matrix = {
        {1,2,3,4}, 
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    cout<<"Matrix"<<endl;

    for(auto& row : matrix){
        for(int val : row){
            cout<<setw(2)<<setfill('0')<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}