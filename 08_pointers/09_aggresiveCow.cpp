#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//Revision Day 27 [11/5/26]

/*
    Leetcode 1552 : Magnetic Force Between Two Balls

    Aggressive Cows Problem

    Approach:
    - Sort the stall positions.
    - Apply Binary Search on the answer (minimum distance between cows).
    - For each candidate distance, greedily place cows in stalls.
    - If all cows can be placed, try a larger distance.
    - Otherwise, try a smaller distance.

    Time Complexity : O(n log n + n log(maxDistance))

    Space Complexity : O(1)

    Concept : Binary Search on Answer + Greedy Placement

*/

bool isPossible(vector<int> &arr, int n, int c, int minAllowedDist){    //minAllowedDist = mid
    int cows = 1, lastStalPos = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]-lastStalPos >= minAllowedDist){
            cows++;
            lastStalPos = arr[i];
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}

int aggresiveCow(vector<int> &arr, int n, int c){

    sort(arr.begin(), arr.end());

    int st = 1, end = arr[n-1] - arr[0], ans = -1;
   
    //Binary Search
    while(st <= end){
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, c, mid)){
            ans = mid;
            //try larger dist
            st = mid+1;
        } else {
            //try smaller dist
            end = mid-1;
        }
    }
    return ans;
}

int main(){

    //n = stalls with positions on a number line
    //c = cows

    int n = 5, c = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout<<"Min distance of cow placed ";
    cout<<aggresiveCow(arr, n, c)<<endl;
    
    return 0;
}