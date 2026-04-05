#include<iostream>
#include<climits>
using namespace std;

int getMaxSum(int mat[][3],int row, int col){
    int maxRsum = INT_MIN;
    int maxCsum = INT_MIN;

    for(int i=0;i<row;i++){
        int rowSum = 0;
        for(int j=0;j<col;j++){
            rowSum += mat[i][j];
        }
        maxRsum = max(maxRsum, rowSum);
    }

    for(int j=0;j<col;j++){
        int colSum = 0;
        for(int i=0;i<row;i++){
            colSum += mat[i][j];
        }
        maxCsum = max(maxCsum,colSum);
    }
    cout<<"sum of column "<<maxCsum<<endl;
    return maxRsum;
}

int main(){

    int mat[3][3] = {{1,200,3},{40,5,6},{9,8,7}};
    cout<<getMaxSum(mat,3,3);
    return 0;
}