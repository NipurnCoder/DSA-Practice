#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Revision Day 57

/*
    LeetCode  217, 219 :  Find Duplicate using Hash Set & II
    LeetCode 1207 : Unique Number of Occurence

    Topic : Duplicate Number

    Store visited elements in unordered_set.
    If an element is already present, it is the duplicate.

    Time: O(n)
    Space: O(n)
*/

int findDuplicate(vector<int>&arr){

    unordered_set<int> s;

    for(int val : arr){
        if(s.find(val) != s.end()){
            return val;
        }
        s.insert(val);
    }

    return -1;
}

int main(){

    vector<int> arr = {3,1,9,9,4};
    cout<<"Duplicate no "<<findDuplicate(arr);

    return 0;
}