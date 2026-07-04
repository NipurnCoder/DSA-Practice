#include<iostream>
#include<climits>
using namespace std;

//Revision Day 49

/*
    LeetCode 1380 : Lucky Numbers in a Matrix

    Concept :

    - Row-wise Traversal
    - Column-wise Traversal
    - Maximum Row Sum
    - Maximum Column Sum
    - 2D Array Iteration Practice

    Time Complexity : O(row × col)
    Space Complexity: O(1)

*/

int getMaxSum(int mat[][3],int row, int col){

    int maxRsum = INT_MIN;
    int maxCsum = INT_MIN;

    int r = -1;
    int c = -1;

    //Row Sum
    for(int i=0; i<row; i++){
        int rowSum = 0;

        for(int j=0; j<col; j++){
            rowSum += mat[i][j];
        }
        //maxRsum = max(maxRsum, rowSum);

        if(rowSum > maxRsum){
            maxRsum = rowSum;
            r = i;
        }
    }

    //Column Sum
    for(int j=0; j<col; j++){
        int colSum = 0;

        for(int i=0; i<row; i++){
            colSum += mat[i][j];
        }
        //maxCsum = max(maxCsum, colSum);

        if(colSum > maxCsum){
            maxCsum = colSum;
            c = j;
        }
    }

    cout<<"Max sum of column "<<c<<" is : "<<maxCsum<<endl;
    cout<<"Max sum of row "<<r<<" is : ";

    return maxRsum;
}

int main(){

    int mat[3][3] = {
        {1,2,3},
        {4,5,0},
        {0,8,7}
    };

    cout<<getMaxSum(mat,3,3);

    return 0;
}