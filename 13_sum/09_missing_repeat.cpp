#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// Revision Day 55

/*
    LeetCode : 2965, 645, 268, 217

    Topic: Find Missing and Repeated Values (LC 2965)

    Concepts Revised: findMisRep

    1. unordered_set for detecting duplicate elements.
    2. Sum formula:
       Sum of first N numbers = N * (N + 1) / 2
    3. Difference between expected sum and actual sum to find the missing value.
    4. Traversing a 2D vector using nested loops.

    Formula:
    missing = expectedSum + duplicate - actualSum
    

    Concepts Revised: findMissingAndRepeatedValues

    1. unordered_map to store frequency of each number.
    2. Traverse a 2D grid using nested range-based loops.
    3. Count occurrences of each value.
    4. Check numbers from 1 to n²:
       - Frequency = 0 -> Missing number
       - Frequency = 2 -> Repeated number
    5. Return answer as {duplicate, missing}.

       Time Complexity: O(n²)
       Space Complexity: O(n²)
*/

vector<int> findMisRep(vector<vector<int>>& grid){

    vector<int> ans;
    unordered_set<int> s;

    int a, b;
    int n = grid.size();

    int expSum = 0, actualSum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    } 
    
    expSum = ((n*n)*((n*n)+1))/2;

    b = expSum + a - actualSum;

    ans.push_back(b);

    return ans;
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int missing = -1;
    int duplicate = -1;

    unordered_map<int, int> freq;

    for(auto& row : grid){
        for(int val : row){
            freq[val]++;
        }
    }
    for(int num = 1; num<=n*n; num++){
        if(!freq.count(num)){
            missing = num;
        }
        else if(freq[num] == 2){
            duplicate = num;
        }
    }
    return {duplicate, missing};
}


int main(){

    vector<vector<int>> grid = {{9,1,5},{8,3,2},{3,4,6}}; 
    vector<int> result = findMisRep(grid);

    cout<<"duplicate, missing = ";
    for(int i:result){
        cout<<i<<" ";
    }

    return 0;
}