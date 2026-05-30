#include <iostream>
#include <vector>
using namespace std;

//Revision Day 16

/*
    LeertCode - 167 : Two Sum II Input Array is Sorted

    Approach - Two Pointers
    Ptr1 at idx = 0
    ptr2 at idx = n-1
    add both ptr1 + ptr2 = pairSum
    compare pairsum with target
    update ptrs

    Time - O(n)
    Space - O(1)
*/

vector<int> pair_sum (vector<int>nums, int target)
{
    vector<int> ans;

    int n = nums.size();
    //Initialize the Pointers
    //Ptr1 = i, Ptr2 = j
    int i=0, j=n-1;

    while(i<j)
    {
        int pairsum = nums[i]+nums[j];
        
        if(pairsum>target){
            //pairsum need to be small
            j--;
        }
        else if(pairsum<target){
            //pairsum need to big
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
    int target = 12;

    vector<int> ans = pair_sum(nums, target);
    {
        cout<<ans[0]<<", "<<ans[1];
        return 0;
    }
    return 0;
}

