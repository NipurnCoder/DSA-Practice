#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Revision Day 92

/*
    LeetCode 739 : Daily Temperatures

    Topic: Next Greater Element using Monotonic Stack

    Approach:
    1. Traverse the array from right to left.
    2. Remove all elements from the stack that are <= arr[i].
    3. The stack top is the next greater element.
    4. If the stack is empty, answer is -1.
    5. Push arr[i] into the stack.

    Key Point:
    The stack maintains elements that can be the next greater
    element for upcoming elements on the left.

    Time Complexity  : O(n)
    Space Complexity : O(n)
*/

int main(){
    
    vector<int> arr = {6, 8, 0, 1, 3};

    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i=arr.size()-1; i>=0; i--){

        while(s.size() > 0 && s.top() <= arr[i]){
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
