#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAllSubset(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>> &subset){
    if(i == arr.size()){
        subset.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    getAllSubset(arr, ans, i+1, subset);

    ans.pop_back();

    int idx = i+1;
    while(idx < arr.size() && arr[idx] == arr[idx-1]) idx++;

    getAllSubset(arr, ans, idx, subset);

}

int main(){
    
    vector<vector<int>> subset;
    vector<int> arr = {1,2,2};
    vector<int> ans;
    sort(arr.begin(), arr.end());

    getAllSubset(arr, ans, 0, subset);

    for(auto &v : subset){
        cout<<"{ ";
        for(int x : v) cout<<x<<" ";
        cout<<"}"<<endl;
    }
    return 0;
} 