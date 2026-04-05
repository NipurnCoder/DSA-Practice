#include<iostream>
using namespace std;

bool isFound(int matrix[][3], int row, int col, int tar){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j] == tar){
                pair<int,int>p = {i+1,j+1};
                cout<<"coordinate(r,c) "<<p.first<<","<<p.second<<endl;
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
    cout<<isFound(matrix, row, col , 7)<<endl;

    // cout<<"Enter the elments "<<endl;
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cin>>matrix[i][j];
    //     }
    // }

    // cout<<endl<<"The matrix is "<<endl;
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}