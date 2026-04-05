#include<iostream>
#include<string>
using namespace std;

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