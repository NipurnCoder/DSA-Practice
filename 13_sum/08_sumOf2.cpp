#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>&arr, int tar){
    unordered_map<int, int> m;
    vector<int> ans;
    //int tar = 9;

    for(int i=0; i<arr.size(); i++){
        int first = arr[i];
        int second = tar - first;

        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            //cout<< ans;
            break;
        }
        m[first] = i;
    }
    return ans;
}

int main(){
    vector<int> arr = {5,2,11,7,15};
    vector<int> result = twoSum(arr, 9);
    cout<<"Indises ";
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl<<"Values ";
    for(int i:result){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}