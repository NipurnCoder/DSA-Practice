#include<iostream>
#include<vector>
using namespace std;

//Revision Day 17

/*
    Approach - Brute Force
    Traverse one by one in inner loop and outer loop
    If found target
    Push in ans

    Time - O(n*n)
    Space - O(1)

*/

vector<int> pair_sum(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();

    //Traverse 1st element
    for(int i=0;i<n;i++){
        //Traverse 2nd elemnt
        for(int j=i+1;j<n;j++){
            //if Target Found then Push in ans
            if(nums[i]+nums[j]==target){

                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 26;

    vector<int> ans = pair_sum(nums, target);
    cout<<ans[0]<<", "<<ans[1]<<endl;

    return 0;
}