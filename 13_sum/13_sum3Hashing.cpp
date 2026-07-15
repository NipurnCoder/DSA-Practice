#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Revision Day 60

/*
    LeetCode 16, 881 : Boat to Save People
    LeetCode 611 : Valid Triangle Number

    Topic: 3Sum using Hashing + Set
    
    Idea:
    1. Fix the first element.
    2. Use a hash set to find the required third element for each second element.
    3. Sort each triplet before inserting into a set to avoid duplicates.
    4. Return all unique triplets whose sum is 0.

    Time Complexity: O(n² log n)
    Space Complexity: O(n)
*/

vector<vector<int>> sum3hash(vector<int>& num){
    int n = num.size();

    set<vector<int>> uniqueTriplet;

    for(int i = 0; i<n; i++){ //first
        int tar = -num[i];
        set<int> s;

        for(int j = i+1; j<n; j++){    //num[j]=second
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

