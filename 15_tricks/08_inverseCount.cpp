#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;

int bruteInverse(vector<int> &arr){
    int n = arr.size();
    int InvCount = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                InvCount++;
                cout<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }
    return InvCount;
}

int main(){
    vector<int> arr = {6,3,5,2,7};
    cout<<bruteInverse(arr);
    return 0;
}