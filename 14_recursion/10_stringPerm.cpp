#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void stringPerm(string& s, int idx, vector<string>& ans){

    if(idx == s.size()){
        ans.push_back(s);
        return ;
    }

    for(int i=idx; i<s.size(); i++){
        swap(s[idx], s[i]);
        stringPerm(s, idx+1, ans);

        swap(s[idx], s[i]);
    }


}
int main(){
    string s = {"abc"};
    vector<string> ans ;

    stringPerm(s, 0, ans);

    for(string str : ans){
        cout<<str<<endl;
    }
    return 0;
}