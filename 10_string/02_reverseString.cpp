#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void reverseString(vector<char>& str){
    int st = 0, end = str.size()-1;

    while(st<end){
        swap(str[st++],str[end--]);
    }

    for(char i : str){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector<char> str = {'h','e','l','l','o'};
    reverseString(str);

    string s = "hello";

    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}


