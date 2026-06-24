#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Revision Day 40

/*
    LeetCode 567 - Permutation in String

    Slinding Window (Brute Force)

    Approach:
    - Store frequency of s1.
    - For every window of size s1.length() in s2:
        - Build its frequency array.
        - Compare both frequency arrays.
    - If frequencies match, permutation exists.

    Time Complexity: O(n * m)
    Space Complexity: O(26) = O(1)
*/

bool isFreqSame(int freq1[], int freq2[]){  //O(1)
    for(int i=0; i<26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){

    //all element's val is initialized with 0
    int freq[26] = {0};
   
    for(int i=0; i<s1.length(); i++){ 
        // int idx = s1[i] - 'a';
        // freq[idx]++;
        
        //assinging index
        freq[s1[i] - 'a']++; 
    }

    //Sliding Window Approach
    int windSize = s1.length();

    for(int i=0; i<s2.length(); i++){
        int windIdx = 0, idx = i; 
        int windFreq[26]  = {0};

        while(windIdx < windSize && idx < s2.length()){
            windFreq[s2[idx] - 'a']++;
            windIdx++; idx++;
        }
        if(isFreqSame(freq, windFreq)){
            return true;
        }
    }
    return false;
}

int main(){

    string s1 = "axb";
    string s2 = "djshdabxsbasjd";

    if(checkInclusion(s1, s2)){
        cout<<"Sub Array lies in Array "<<endl;
    } 
    else {
        cout<<"Not occurs "<<endl;
    }

    //checkInclusion(s1, s2);

    return 0;
}