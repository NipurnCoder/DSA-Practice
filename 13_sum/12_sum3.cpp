#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> sumOf3(vector<int>& arr){

    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = arr.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){

                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int>trip = {arr[i],arr[j],arr[k]};
                    sort(trip.begin(), trip.end());

                    if(s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sumOf3(arr);

    for(auto &trip : result){
        for(int i : trip){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}