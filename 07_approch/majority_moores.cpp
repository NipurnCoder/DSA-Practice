#include<iostream>
#include<vector>
using namespace std;

//Revision Day 14

/*
    LeetCode - 169, 229
    
    Approach : Boyer Moore Voting Algorithm

    Time : O(n)
    Space : O(n)

*/

int majority(vector<int> nums){
    int n = nums.size();
    int freq=0, ans=0;

    for(int i=0;i<n;i++){
        if(freq==0){
            ans = nums[i];
           // freq=1;
        }
        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }    
            
        return ans;
    }
}

int main(){

    //vector<int>nums = {2,3,4,5,5,5,5,4,3,4,2,1};
    vector<int> nums = {3,3,3,4,2,2,5,5,4,5,3,3,3,3,3};
    int m = majority(nums);

    cout<<"Majority element is : "<<m<<endl;

    return 0;
}