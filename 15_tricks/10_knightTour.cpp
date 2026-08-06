#include<iostream>
#include<vector>
using namespace std;

//Revision Day 83 [06/08/2026]

/*
    LeetCode 130 : Surrounded Regions
            1219 : Path with Maximum Gold
            1020 : Number of Enclaves

    Topics Covered:
    1. Backtracking / Recursion
    2. Knight's Tour Validation (LeetCode 2596)
    3. Recursive Grid Traversal
    4. Base Cases and Boundary Checking
    5. Exploring 8 Knight Moves
    6. Validating Sequential Path in a Matrix

    Learned:
    - How to recursively traverse a grid using knight moves.
    - Importance of strong base cases to terminate recursion.
    - Boundary checking before accessing grid cells.
    - Difference between brute-force recursive exploration and the optimal
        O(n²) position-mapping approach.
    - When recursion is correct but not the most efficient solution.
*/    

bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal){

    //Base Case
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal){
        return false;
    }

    //2nd Base Case - If reached at last return true
    if(expVal == n*n-1){
        return true;
    }

    //8 possible moves
    int ans1 = isValid(grid, r-2, c+1, n, expVal+1);
    int ans2 = isValid(grid, r-1, c+2, n, expVal+1);
    int ans3 = isValid(grid, r+1, c+2, n, expVal+1);
    int ans4 = isValid(grid, r+2, c+1, n, expVal+1);
    int ans5 = isValid(grid, r+2, c-1, n, expVal+1);
    int ans6 = isValid(grid, r+1, c-2, n, expVal+1);
    int ans7 = isValid(grid, r-1, c-2, n, expVal+1);
    int ans8 = isValid(grid, r-2, c-1, n, expVal+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(vector<vector<int>>& grid){
    return isValid(grid, 0, 0, grid.size(), 0);
}

int main(){

    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};

    cout<< checkValidGrid(grid)<<endl;
    return 0;
}