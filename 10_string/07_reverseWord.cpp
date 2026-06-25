#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Revision Day 41

/*
    LeetCode : 151 - Reverse Words in a String

    Approach :
        - Reverse the entire string.
        - Traverse the reversed string and extract each word.
        - Reverse every extracted word to restore its characters.
        - Append valid words to the answer string.
        - Ignore leading, trailing, and multiple spaces.

    Example :
        Input  : "the sky is blue"
        Reverse String : "eulb si yks eht"
        Reverse Words  : "blue is sky the"

    Time Complexity : O(n)
    Space Complexity : O(n)
*/

void reverseString(string s){   //O(n)

    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for(int i=0; i<n; i++){
        string word = "";
        while(i<n && s[i] != ' '){
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.length()>0){
            ans += " " + word;
        }
    }
    cout<< ans.substr(1);
}

int main(){

    string s ;
    cout<<"Enter the string : ";
    getline(cin,s);
    cout<<"Reversed string : ";

    reverseString(s);
    return 0;
}
