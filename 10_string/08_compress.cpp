#include<iostream>
#include<string>
using namespace std;

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

    string chars = "aabbbcccc";

    compress(chars);
    return 0;
}