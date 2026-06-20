#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Revision Day 36

/*
    LeetCode 344 - Reverse String
    
    Reverse String

    Approach 1:
    - Use two pointers (start, end)
    - Swap characters until start < end

    Approach 2:
    - Use STL reverse() function

    Time Complexity : O(n)
    Space Complexity : O(1)

*/

void reverseString(vector<char>& str){

    int st = 0, end = str.size()-1;

    //reverse string in vector form
    while(st<end){
        //using swap function
        swap(str[st++],str[end--]);
    }

    //print the string
    for(char i : str){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector<char> str = {'h','e','l','l','o'};
    reverseString(str);

    string s = "hello";
    
    //reverse string with reverse function
    reverse(s.begin(), s.end());

    cout<<s<<endl;

    return 0;
}


