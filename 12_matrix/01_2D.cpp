#include<iostream>
using namespace std;

int main(){
    // int arr[5] = {2,4,3,5,6};
    // int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    int matrix[4][3];
    int row = 4;
    int col = 3;

    cout<<"Enter the elements "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"The matrix is "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<matrix[3][3];
    return 0;
}  