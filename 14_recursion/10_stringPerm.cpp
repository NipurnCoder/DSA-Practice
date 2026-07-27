#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//Revision Day 73

/*
    LeetCode 17 : Letter Combinations of a Phone Number
             22 : Generate Parentheses

    Problem: String Permutations using Backtracking
    Topic: Backtracking

    Time Complexity: O(n × n!)
    Space Complexity: O(n)

    ✔ Learned:
    - Fix one character at each recursion level.
    - Generate permutations by swapping the current index with every possible index.
    - After recursion, swap back to restore the original string (Backtracking).
    - Base case: when idx == s.size(), one complete permutation is formed.
    - Swap → Explore → Backtrack.
    - This approach works for strings with distinct characters.
    - For strings with duplicate characters, extra duplicate-skipping logic is required.
*/

void stringPerm(string& s, int idx, vector<string>& ans){

    //Base Case
    if(idx == s.size()){
        ans.push_back(s);
        return ;
    }

    for(int i=idx; i<s.size(); i++){

        swap(s[idx], s[i]);

        //Recursion of Fnc
        stringPerm(s, idx+1, ans);

        //Back Tracking
        swap(s[idx], s[i]);
    }


}
int main(){

    string s = {"abc"};
    vector<string> ans ;

    stringPerm(s, 0, ans);

    for(string str : ans){
        cout<<str<<endl;
    }

    return 0;
}