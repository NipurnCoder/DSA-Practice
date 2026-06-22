#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Revision Day 38

/*
    LeetCode 125 : Valid Palindrome

    Approach:
    - Use two pointers.
    - Skip non-alphanumeric characters.
    - Compare characters ignoring case.
    - If all characters match, return true.

    Time Complexity : O(n)
    Space Complexity : O(1)
*/

bool isAlpha(char ch){

    //Allow numbers and alphabets
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    return false;
}

bool isPalindrome(string s){

    int st = 0, end = s.length()-1;

    while(st < end){ 

        if(!isAlpha(s[st])){  
            st++; continue;
        }
        if(!isAlpha(s[end])){
            end--; continue;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++;
        end--;
    }           
    return true;
}

int main(){

    string s = "A/B//]sgSb?/a";
    isPalindrome(s);

    if(isPalindrome(s)){
        cout<<"Valid Palindrome !"<<endl;
    }
    else{
        cout<<"Non Valid Palindrome !"<<endl;
    }
    return 0;
}