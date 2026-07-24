#include<iostream>
#include<vector>
using namespace std;

//Revision Day 69

/*
    LeetCode 40, 216 : Combination Sum II & III

    Topic: Recursion + Backtracking
    Problem: Generate All Subsets (Power Set)

    Approach:
    - At every index, make two choices:
        1. Include the current element.
        2. Exclude the current element.
    - Use recursion to explore both choices.
    - After the include call, remove the last element
      (backtracking) to restore the previous state before
      exploring the exclude choice.
    - When all elements have been processed, print the
      current subset.

    Time Complexity: O(n * 2^n)
    Space Complexity: O(n)

    ✔ Learned:
    - Every element creates two recursive branches:
      include or exclude.
    - Backtracking (pop_back()) restores the previous state.
    - Number of subsets for n elements = 2^n.
    - The empty subset is also a valid subset.
    - This choose → recurse → backtrack pattern is the
      foundation for many backtracking problems.
*/

void subset(vector<int> &arr, vector<int> &ans, int i){

    if(i == arr.size()){

        for(int val : ans){
            cout<<val<<" ";
        }

        cout<<endl;
        return;
    }

    //include
    ans.push_back(arr[i]);
    subset(arr, ans, i+1);

    //backtracking
    ans.pop_back();
    //exclude
    subset(arr, ans, i+1);
}

int main(){

    vector<int> arr = {1,2,3};
    vector<int> ans;

    subset(arr, ans, 0);
    return 0;
}
