#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Revision Day 91

/*
    LeetCode 901 - Online Stock Span

    Topic : Stock Span Problem
    Algorithm : Monotonic Decreasing Stack

    Key Idea:
    For every price, find the previous greater price.
    The stack stores indices of prices in decreasing order.

    Steps:
    1. Remove all previous prices <= current price.
    2. If stack is empty, span = i + 1.
    3. Otherwise, span = i - previousGreaterIndex.
    4. Push current index into the stack.

    Key Point:
    Store indices instead of prices so we can directly calculate the span.

    Time Complexity  : O(n)
    Space Complexity : O(n)

    Example:
    price = {100, 80, 60, 70, 60, 75, 85}
    answer = {1, 1, 1, 2, 1, 4, 6}

*/

int main(){

    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    int n = price.size();
    
    vector<int> ans(n, 0);
    stack<int> s;

    for(int i=0; i<n; i++){
        while(s.size() > 0 && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.size() == 0){  //s.empty()
            ans[i] = i+1;
        } else{
            ans[i] = i - s.top();   //i-prevHigh
        }
        s.push(i);
    }

    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}

