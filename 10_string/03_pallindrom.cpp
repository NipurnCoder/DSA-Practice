#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void palindrom(vector<char>&str){
    int st = 0, end = str.size()-1;
    while(st<end){
        if(str[st] != str[end]){
            cout<<"Unvalid Palindrom !! "<<endl;
            return;
        }
        st++;
        end--;
    }
    cout<<"Valid Palindrom "<<endl;
    // while(st<end){
    //     if(str[st++] == str[end--]){
    //         cout<<"Valid Palindrom "<<endl;
    //     }
    //     else {
    //         cout<<"Unvalid palindrome !!"<<endl;
    //     }
    // }
}
void palStr(const string& s){
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
     palStr(s);

    // if(s.begin() == s.end()){
    //     cout<<"This is a Plindrome "<<endl;
    // }
    // else{
    //     cout<<"Not! a Palindrom"<<endl;
    // }

    return 0;
}
