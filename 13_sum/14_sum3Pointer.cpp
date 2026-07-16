#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 61

/*
    LeetCode 923 : 3 Sum with Multiplicity
    
    Topic: 3Sum (Two Pointers)

    - Sort the array first.
    - Fix one element and use two pointers (left & right).
    - Move pointers based on the sum:
        sum < 0  -> left++
        sum > 0  -> right--
        sum == 0 -> store triplet, move both pointers, skip duplicates.
    - Skip duplicate first elements to avoid repeated triplets.

    Time Complexity: O(n²)
    Space Complexity: O(1) (excluding output)
*/    

vector<vector<int>> sum3pointer(vector<int>& num){

    vector<vector<int>> ans;
    int n = num.size();

    sort(num.begin(), num.end());

    for(int i=0; i<n-2; i++){

        if(i > 0 && num[i] == num[i-1]) continue;

        int j = i+1, k = n-1;

        while(j < k){
            int sum = num[i] + num[j] + num[k];

            if(sum < 0){
                j++;
            } 
            else if(sum > 0){
                k--;
            } 
            else{
                ans.push_back({num[i], num[j], num[k]});
                j++; k--;

                while(j < k && num[j] == num[j-1]) j++;
                while(j < k && num[k] == num[k+1]) k--;
            }
        }
    }

    return ans;
}

int main(){

    vector<int> num = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sum3pointer(num);

    for(auto &trip : result){
        for(int i : trip){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}

