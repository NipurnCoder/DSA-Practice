#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 62

/*
    LeetCode 18 : 4 Sum, 812 Largest Triangle Area

    Topic: 4Sum 

    Approach: Sorting + Two Nested Loops + Two Pointers

    Key Learnings:
    - Fixed first two elements and used two pointers for the remaining two.
    - Skipped duplicates to avoid repeated quadruplets.
    - Used long long to prevent integer overflow during sum calculation.
    - Practiced handling multiple pointers and duplicate elimination.

    Time Complexity: O(n^3)
    Space Complexity: O(1) (excluding output)
    
*/    

vector<vector<int>> sum4(vector<int>& num, int tar){

    vector<vector<int>> ans;
    int n = num.size();

    sort(num.begin(), num.end());

    for(int i=0; i<n-3; i++){

        if(i > 0 && num[i] == num[i-1]) continue;

        for(int j = i+1; j<n; ){
            int p = j+1; 
            int q = n-1;

            while(p < q){

                long long sum = (long long) num[i]+ (long long) num[j]+ (long long) num[p]+ (long long) num[q];

                if(sum < tar){
                    p++;
                } 
                else if(sum > tar){
                    q--;
                }
                else{
                    ans.push_back({num[i], num[j], num[p], num[q]});
                    p++; q--;

                    while(p < q && num[p] == num[p-1]) p++;
                    while(p < q && num[q] == num[q+1]) q--;
                }
            }
            j++;

            while(j < n && num[j] == num[j-1]) j++;
        }
    }

    return ans;
}

int main(){

    vector<int> num = {-2,-1,-1,1,1,2,2};
    //int tar = 0;

    vector<vector<int>> result = sum4(num,0);

    for(auto &quad : result){
        for(int i : quad){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}