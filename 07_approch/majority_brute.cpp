// #include<iostream>
// #include<vector>
// using namespace std;

// int majority(vector<int>nums)//, int target)
// {
//     int n = nums.size();

//     //vector<int> val;
//     for(int val : nums){
//         int freq = 0;
//         for(int el : nums){
//             if(el == val){
//                 freq++;
//             }
//         }
//         if(freq > n/2){
//             return val;
//         }
//     }
//     return -1;
// }

// int main(){

//     vector<int>nums = {3,4,5,3,3,3,3,2,1};
//     //int target = 3;

//     int ans = majority (nums)//, target);
//     {
//         if(ans!=-1){
//             cout<<"Majority element is : "<<ans<<endl;
//         }
//         else{
//             cout<<"No Majority element is found "<<endl;
//         }
//         return 0;
//     }
// }


#include <iostream>
#include <vector>
using namespace std;

int majority(vector<int> nums)
{
    int n = nums.size();

    for (int val : nums)
    {
        int freq = 0;
        for (int el : nums)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > n / 2)
        {
            return val; // majority element found
        }
    }
    return -1; // no majority element
}

int main()
{
    vector<int> nums = {3, 4, 5, 3, 3, 3, 3, 2, 1};

    int ans = majority(nums);

    if (ans != -1)
    {
        cout << "Majority element is: " << ans << endl;
    }
    else
    {
        cout << "No majority element found." << endl;
    }

    return 0;
}
