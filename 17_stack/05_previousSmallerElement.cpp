#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Revision Day 93

/*
    LeetCode 1475 : Final Prices With a Special Discount in a Shop

    Topic: Previous Smaller Element (PSE):

    Given an array, find the nearest smaller element
    on the left side for every element.

    Approach:
    1. Use a monotonic increasing stack.
    2. For every element:
    - Pop elements >= current element.
    - If stack is empty, answer = -1.
    - Otherwise, stack top is the previous smaller element.
    - Push current element into stack.

    Example:
    arr = {3, 5, 2, 8, 6}
    ans = {-1, 3, -1, 2, 2}

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

int main(){

    vector<int> arr = {3, 5, 2, 8, 6};

    stack<int> s;
    vector<int> ans(arr.size(), 0);
    
    for(int i=0; i<arr.size(); i++){

        while(s.size() > 0 && s.top() >= arr[i]){       // TC, SC : O(n)
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        } else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}