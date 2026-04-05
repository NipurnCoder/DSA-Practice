#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void permutation(vector<int>& nums, int idx, vector<vector<int>>& ans){

    if(idx == nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int i=idx; i<nums.size(); i++){
        swap(nums[idx], nums[i]);
        permutation(nums, idx+1, ans);

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