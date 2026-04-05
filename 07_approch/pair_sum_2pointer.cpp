#include <iostream>
#include <vector>
using namespace std;

vector<int> pair_sum (vector<int>nums, int target)
{
    vector<int> ans;

    int n = nums.size();
    int i=0, j=n-1;

    while(i<j)
    {
        int pairsum = nums[i]+nums[j];
        if(pairsum>target){
            j--;
        }
        else if(pairsum<target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int>nums = {2,4,6,7,8};
    int target = 15;

    vector<int> ans = pair_sum(nums, target);
    {
        cout<<ans[0]<<", "<<ans[1];
        return 0;
    }
}

