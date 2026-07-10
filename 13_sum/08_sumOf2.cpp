#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Revision Day 55 [10/07/26]

/*
    LeetCode 560 - Subarray Sum Equals K

    1. Update running sum.
    2. Check if (sum - k) exists.
    3. If yes, add its frequency to the answer.
    4. Store the current sum in the map.

    LeetCode 49  - Group Anagrams

    Topic:
    -> Hash Map (unordered_map)
    -> Two Sum Problem (LC 1)

    Concepts:
    -> Store value -> index in unordered_map
    -> For every element, search its complement (target - current)
    -> If complement exists, return both indices
    -> Otherwise insert current element into map

    Time  : O(n)
    Space : O(n)

*/

vector<int> twoSum(vector<int>&arr, int tar){

    unordered_map<int, int> m;
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){

        int first = arr[i];
        int second = tar - first;

        if(m.find(second) != m.end()){

            ans.push_back(m[second]);
            ans.push_back(i);

            break;
        }

        m[first] = i;
    }

    return ans;
}

int main(){

    vector<int> arr = {5,2,11,4,15};
    vector<int> result = twoSum(arr, 6);

    cout<<"Indices ";
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl<<"Values ";

    for(int i:result){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    if(result.empty()){
        cout<<"Result Not Found ";
    }

    return 0;
}