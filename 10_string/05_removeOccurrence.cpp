#include<iostream>
#include<string>
using namespace std;

// Revision Day 39

/*
    LeetCode 1910: Remove All Occurrences of a Substring
    
    Remove All Occurrences of a Substring

    Approach:
    - Find the substring using find().
    - If found, erase it using erase().
    - Repeat until substring is not present.

    Time Complexity: O(n²) (Worst Case)
    Space Complexity: O(1)
*/

void removeOccurence(string s , string part){
    
    int st = 0, end = s.length()-1;

    while(s.length() > 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    cout<<s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    removeOccurence(s , part);
    return 0;
}