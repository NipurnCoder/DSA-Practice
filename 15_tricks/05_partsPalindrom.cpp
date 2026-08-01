#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//Revision Day 78

/*
    LeetCode 784 : Letter Case Permutation

    Topic: Backtracking – Palindrome Partitioning

    Concepts Revised:

    Generate all possible partitions recursively.
    Choose only palindrome prefixes.
    Backtracking with push/pop.
    Base case when the remaining string becomes empty.
    Recursive exploration of all valid partitions.
*/    

bool isPalindrom(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void getAllPart(string s, vector<vector<string>>& ans, vector<string>& parts){

    if(s.size() == 0){
        ans.push_back(parts);
        return;
    }

    for(int i=0; i<s.size(); i++){
        string part = s.substr(0,i+1);

        if(isPalindrom(part)){
            parts.push_back(part);

            getAllPart(s.substr(i+1), ans, parts);
            parts.pop_back();
        }
    }
}

int main(){
    string s = {'a','a','b'};
    vector<vector<string>> ans;
    vector<string> parts;

    getAllPart(s, ans, parts);

    for(auto val : ans){
        cout<<"{";
        for(auto result : val){
            cout<<result<<",";
        }
        cout<<"}"<<endl;
    }
    return 0;
}