#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 37 [21/6/26]

/*
    LeetCode 2108 : Find First Palindromic String in the Array

    (Basic Palindrome Check)

    Approach:
        - Use two pointers (start and end).
        - Compare characters from both ends.
        - If any pair doesn't match, it's not a palindrome.
        - Otherwise move both pointers inward.
        - If all pairs match, it's a palindrome.

    Time Complexity : O(n)
    Space Complexity : O(1)
*/

void palindrom(vector<char>&str){

    int st = 0, end = str.size()-1;

    // while(st<end){

    //     if(str[st] != str[end]){
    //         cout<<"Unvalid Palindrom !! "<<endl;
    //         return;
    //     }
    //     st++;
    //     end--;
    // }
    // cout<<"Valid Palindrom "<<endl;

    //2nd way

    while(st<end){
        if(str[st++] != str[end--]){
            cout<<"UnValid Palindrom "<<endl;
             return;
        }
    }
      cout<<"Valid palindrome !! "<<endl;
}

void palindromStr(const string& s){
        int st = 0, end = s.length()-1;

        while(st<end){
            if(s[st] != s[end]){
                cout<<"Not Palindrom "<<endl;
                return;
            }
            st++;
            end--;
        }
        cout<<"Palindrom "<<endl;
    }

int main(){

    vector<char>str = {'r','a','c','e','c','a','r'};
    palindrom(str);

    string s = "RACeCAR";
    //palindromStr(s);

    //Another way

    string temp = s;
    reverse(temp.begin(), temp.end());

    if(temp == s)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
