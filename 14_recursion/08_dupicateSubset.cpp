#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 70 [25/07/2026]

/*
    LeetCode 77 Combination

    Topic: Recursion + Backtracking
    Problem: Generate Unique Subsets (Subset II)

    Time Complexity : O(n * 2^n)
    Space Complexity: O(n) recursion
                      O(n * 2^n) output storage

    ✔ Learned:
    - Sort the array first so duplicates become adjacent.
    - Use include/exclude recursion.
    - After excluding an element, skip all consecutive duplicates.
    - This avoids generating duplicate subsets without using a set.
    - Backtracking is done using push_back() and pop_back().
*/

void getAllSubset(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>> &subset){

    if(i == arr.size()){
        subset.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    
    getAllSubset(arr, ans, i+1, subset);

    ans.pop_back();

    int idx = i+1;
    while(idx < arr.size() && arr[idx] == arr[idx-1]) idx++;

    getAllSubset(arr, ans, idx, subset);

}

int main(){
    
    vector<vector<int>> subset;
    vector<int> arr = {1,2,2};
    vector<int> ans;

    sort(arr.begin(), arr.end());

    getAllSubset(arr, ans, 0, subset);

    for(auto &v : subset){
        cout<<"{ ";

        for(int x : v) cout<<x<<" ";
        cout<<"}"<<endl;
    }

    return 0;
} 