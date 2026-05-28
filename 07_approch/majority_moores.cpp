#include<iostream>
#include<vector>
using namespace std;

//Revision Day 14

/*
    LeetCode - 169, 229
    
    Approach : Boyer Moore Voting Algorithm

    Finds element whose freq is more than half of the array's size
    1st increase freq by 1 of element 
    2nd decrease freq if  element not same
    finally, freq left to those element who appear max after freq--

    Time : O(n)
    Space : O(n)

*/

int majority(vector<int> nums){
    int n = nums.size();
    int freq=0, ans=0;

    for(int i=0; i<n; i++){
        if(freq==0){
            ans = nums[i];

        }

        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }    
        cout<<freq<<" ";
    }

    return ans;
}

int main(){

    //vector<int>nums = {2,3,4,5,5,5,5,4,3,4,2,1};
    //vector<int> nums = {1,2,2,1,1,2,2};
    vector<int> nums  = {3,3,3,4,2,2,5,5,4,5,5,5,5,5,3,3};

    int m = majority(nums);

    cout<<"Majority element is : "<<m<<endl;

    return 0;
}