#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 71

/*
    LeetCode 47 : Permutation II

    Topic: Backtracking
    Problem: Generate All Permutations

    Time Complexity: O(n × n!)
    Space Complexity: O(n) (recursive stack)
    Auxiliary Space: O(1) (excluding output)

    ✔ Learned:
    - Fix one element at each position.
    - Swap the current index with every possible element.
    - Recursively generate permutations for the remaining positions.
    - Backtrack by swapping back to restore the original array.
    - Every complete arrangement is stored when idx == nums.size().

    Pattern:
    Fix → Recurse → Undo (Backtrack)
*/

void permutation(vector<int>& nums, int idx, vector<vector<int>>& ans){

    //Base Case
    if(idx == nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int i=idx; i<nums.size(); i++){

        swap(nums[idx], nums[i]);
        permutation(nums, idx+1, ans);

        //BackTracking
        swap(nums[idx], nums[i]);
    }
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;

    permutation(nums, 0, ans);

    for(auto &v : ans){
        for(int x : v) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}