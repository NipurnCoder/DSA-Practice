#include<iostream>
#include<vector>
using namespace std;

bool search(vector<vector<int>>&mat, int target){
    int r = mat.size(), c = mat[0].size();
    int st = 0, end = c-1;

    while(st < r && end >= 0){
        if(target == mat[st][end]){
            return true;
        } else if(target < mat[st][end]){
            end--;
        } else {
            st++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>>mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout<<search(mat, 0)<<endl;
    return 0;
}