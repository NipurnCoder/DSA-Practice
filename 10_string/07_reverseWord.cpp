#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

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
