#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findDuplicate(vector<int>&arr){
    unordered_set<int> s;
    for(int val : arr){
        if(s.find(val) != s.end()){
            return val;
        }
        s.insert(val);
    }
    return -1;
}

int main(){
    vector<int> arr = {3,1,3,4};
    cout<<"Duplicate no "<<findDuplicate(arr);
    return 0;
}