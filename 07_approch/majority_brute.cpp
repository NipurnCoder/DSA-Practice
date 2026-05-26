#include<iostream>
#include<vector>
using namespace std;

//Revision Day 13

/*
    Approach : Brute Force
    Finds element whose freq is more than half of the array's size

    Time = O(n*n)
    Space = O(1)

*/

int majority(vector<int>nums) //int target)
{
    int n = nums.size();

    //vector<int> val;

    //Traverse Value in nums
    for(int val : nums){
        //Initialize freq
        int freq = 0;

        //Traverse each element if found same increase freq
        for(int el : nums){
            if(el == val){
                freq++;
            }
        }

        //Freq should be greater than half size of array
        if(freq > n/2){
            return val;
        }
    }
    return -1;
}

int main(){

    // vector<int>nums = {3,4,5,3,3,3,3,2,1};
    vector<int> nums = {3,3,4,2,5,5,4,5};
    //int target = 3;

    int ans = majority (nums); //target);
    {
        if(ans!=-1){
            cout<<"Majority element is : "<<ans;
        }
        else{
            cout<<"No Majority element is found ";
        }
        return 0;
    }
}