#include<iostream>
#include<string>
using namespace std;

//Revision Day 42

/*
    LeetCode 443 : String Compression

    Topic:
    - String Compression (Two Pointers)
    - In-place String Modification
    - Count Consecutive Characters

    Approach:
    1. Traverse the string.
    2. Count consecutive occurrences of each character.
    3. Write the character once.
    4. If count > 1, write its digits using to_string().
    5. Resize the string to the final compressed length.

    Time Complexity: O(n)
    Space Complexity: O(1) Extra Space
    (ignoring the small string created by to_string())
*/

void compress(string chars){
    int n = chars.length();
    int idx = 0;

    for(int i=0; i<n; i++){
        char ch = chars[i];
        int count = 0;

        while(i<n && chars[i] == ch){
            count++; i++;
        }

        if(count == 1){
            chars[idx++] = ch;
        } else {
            chars[idx++] = ch;
            string str = to_string(count);
            for(char dig : str){
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    cout<<chars<<" "<<idx;
}

int main(){

    string chars = "aabbbcccckk";

    compress(chars);
    return 0;
}