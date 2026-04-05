#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int minAllowedDist){
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

    sort(arr.begin(),arr.end());

    int st = 1, end = arr[n-1]-arr[0],ans =-1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, c)){
            ans = mid;
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 5, c = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout<<aggresiveCow(arr, n, c)<<endl;
    return 0;
}