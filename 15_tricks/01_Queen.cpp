#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Revision Day 74

/*
    LeetCode 51, 52 : N Queen I, II

    Topic: Backtracking - N Queens

    Learned:
    1. Place one queen row by row using recursion.
    2. Check safety using column, upper-left diagonal, and upper-right diagonal.
    3. Horizontal check is unnecessary since each recursive call handles one row.
    4. Generate all valid board configurations through backtracking.
     
    Time Complexity: 
        O(n × n!) with board scanning.

    Optimized approach:
        Use column and diagonal arrays for O(1) safety checks,
        reducing the overall complexity to approximately O(n!).
*/    

bool isSafe(vector<string>& board, int row, int col, int n){
    
    //horizontal
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    //verticle
    for(int i=0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    //left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //right diagonal
    for( int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void Queen(vector<string>& board, int row, int n, vector<vector<string>>& ans){
    if(row == n){
        ans.push_back(board);
        return;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, row, j, n)){
            board[row][j] = 'Q';
            Queen(board, row+1, n, ans);
            board[row][j] = '.';
        }
    }
}

int main(){

    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    Queen(board, 0, n, ans);

    for(auto& result : ans){
        for(string row : result){
            cout<<row<<endl;
        }
        cout<<endl;
    }
    return 0;
} 