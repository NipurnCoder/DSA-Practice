#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char dig){

    //horizontal
    for(int j=0; j<9; j++){
        if(board[row][j] == dig){
            return false;
        }
    }
    //verticle
    for(int i=0; i<9; i++){
        if(board[i][col] == dig){
            return false;
        }
    }
    //grid
    int srow = (row/3)*3;
    int scol = (col/3)*3;

    for(int i=srow; i<=srow+2; i++){
        for(int j=scol; j<=scol+2; j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }
    return true;

}

bool helper(vector<vector<char>>& board, int row, int col){

    // if(row == 9){
    //     return true;
    // }

   // int nextRow = row, nextCol = col+1;
    // if(nextRow == 9){
    //     nextRow = row+1;
    //     nextCol = 0;
    // }

    if(col == 9){       //update col
        row++; col = 0;
    }
    if(row == 9) return true;

    if(board[row][col] != '.'){
        return helper(board, row, col+1);
    }

    for(char dig= '1'; dig<= '9'; dig++){   //backtracking
        if(isSafe(board, row, col, dig)){ 
            board[row][col] = dig;
        
        if(helper(board, row, col+1))
            return true;

            board[row][col] = '.';
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {
        // {'5','3','.','.','7','.','.','.','.'},
        // {'6','.','.','1','9','5','.','.','.'},
        // {'.','9','8','.','.','.','.','6','.'},
        // {'8','.','.','.','6','.','.','.','3'},
        // {'4','.','.','8','.','3','.','.','1'},
        // {'7','.','.','.','2','.','.','.','6'},
        // {'.','6','.','.','.','.','2','8','.'},
        // {'.','.','.','4','1','9','.','.','5'},
        // {'.','.','.','.','8','.','.','7','9'}

        {'2','.','.','.','.','1','4','.','.'},
        {'7','.','.','.','9','.','.','.','.'},
        {'.','3','.','.','5','6','.','.','2'},
        {'.','7','.','2','1','8','5','.','6'},
        {'1','.','2','.','.','5','9','3','.'},
        {'.','6','.','.','.','9','.','.','.'},
        {'6','.','.','.','8','.','.','.','.'},
        {'9','.','.','5','.','3','8','.','.'},
        {'4','1','8','.','2','.','.','6','5'}
    };
    
    helper(board, 0, 0); 

    for(auto& row : board){
        for(char val : row){
            cout<<"["<<val<<"]"<<" ";
        }
        cout<<endl;
    }
    return 0;
}