#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Revision Day 77

/*
    LeetCode 39, 93 : Combination Sum, Restore IP Address

    Topic: Backtracking - Combination Sum

    Learned:
    1. Include-Exclude recursion.
    2. Reuse the same element by staying at the same index.
    3. Move to the next index when excluding an element.
    4. Stop recursion when target < 0 or index reaches the end.
    5. Store the current combination when target == 0.
    6. Avoid generating duplicate recursion paths; no set is needed for LC 39.
*/    

set<vector<int>> s;

void getAllCombination(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin){

    if(idx == arr.size() || tar < 0){
        return;
    }
    if(tar == 0){
        if(s.find(combin) == s.end()){  //unique elements
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);
    //single
    getAllCombination(arr, idx+1, tar-arr[idx], ans, combin);
    //duplicate
    getAllCombination(arr, idx, tar-arr[idx], ans, combin);

    combin.pop_back();
    //exclude
    getAllCombination(arr, idx+1, tar, ans, combin);

}

int main(){
    vector<int> arr = {2,3,5};
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombination(arr, 0, 8, ans, combin);
    
    for(auto val : ans){
        for(auto result : val){
            cout<<"["<<result<<"]";
        }
        cout<<endl;
    }
    return 0;
}