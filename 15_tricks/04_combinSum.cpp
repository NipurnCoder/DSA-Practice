#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

set<vector<int>> s;
void getAllCombination(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin){

    if(idx == arr.size() || tar < 0){
        return;
    }
    if(tar == 0){
        if(s.find(combin) == s.end()){  //unique elements
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);
    //single
    getAllCombination(arr, idx+1, tar-arr[idx], ans, combin);
    //duplicate
    getAllCombination(arr, idx, tar-arr[idx], ans, combin);

    combin.pop_back();
    //exclude
    getAllCombination(arr, idx+1, tar, ans, combin);

}

int main(){
    vector<int> arr = {2,3,5};
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombination(arr, 0, 8, ans, combin);
    
    for(auto val : ans){
        for(auto result : val){
            cout<<"["<<result<<"]";
        }
        cout<<endl;
    }
    return 0;
}