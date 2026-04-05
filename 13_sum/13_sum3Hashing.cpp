#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> sum3hash(vector<int>& num){
    int n = num.size();

    set<vector<int>> uniqueTriplet;

    for(int i = 0; i<n; i++){ //first
        int tar = -num[i];
        set<int> s;

        for(int j=i+1; j<n; j++){    //num[j]=second
            int third = tar - num[j];   //third

            if(s.find(third) != s.end()){
                vector<int> trip = {num[i], num[j], third};
                sort(trip.begin(), trip.end());
                uniqueTriplet.insert(trip);
            }
            s.insert(num[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());
    return ans;
}

int main(){
    vector<int> num = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sum3hash(num);

    for(auto &trip : result){
        for(int i : trip){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}

