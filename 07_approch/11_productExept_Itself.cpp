#include<iostream>
#include<vector>
using namespace std;

vector<int> productExcept_Itself(vector<int>&num){
    int n = num.size();
    vector<int> ans(n,1);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                ans[i] *= num[j];
            }
        }
    }
    return ans;
}

vector<int> optimised(vector<int>&nums){
    int n = nums.size();
    vector<int> ans(n, 1);
    // vector<int> prefix(n, 1);
    // vector<int> suffix(n, 1);

    // for(int i=1; i<n; i++){
    //     prefix[i] = prefix[i-1] * nums[i-1];
    // }

    // for(int i=n-2; i>=0; i--){
    //     suffix[i] = suffix[i+1] * nums[i+1];
    // }

    // for(int i=0; i<n; i++){
    //     ans[i] = prefix[i] * suffix[i];
    // }

    for(int i=1;i<n;i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    
    int suffix=1;
    for(int i=n-2;i>=0;i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;

    }
    return ans;
}

int main(){
    vector<int>num = {1,2,3,4};
       vector<int>nums = {1,2,3,4};

   vector<int> ans = productExcept_Itself(num);

    cout<<"Product is : ";
    for(int x : ans){
        cout<<x<<" ";
    }    
    cout<<endl;
    
    vector<int> optimiseAns = optimised(nums);

    cout<<"Optimised Product is : ";
    for(int y : optimiseAns){
        cout<<y<<" ";
    }
    cout<<endl;

    cout<<"-------THE END------ ";
    return 0;
}