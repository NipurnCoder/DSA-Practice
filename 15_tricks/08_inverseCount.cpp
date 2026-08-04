#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 81

/*
    LeetCode 315 : Count of Smaller Numbers After Self

    Topic – Inversion Count (Revision Comment)

    ✔ Inversion: A pair (i, j) such that i < j and arr[i] > arr[j].
    ✔ Inversion count measures how far an array is from being sorted.
    ✔ Brute force approach checks every pair using two nested loops.
    ✔ Increment the count whenever arr[i] > arr[j].

    Time Complexity: O(n²)
    Space Complexity: O(1)
*/    


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
    cout<<"Inverse Count ";
    return InvCount;
}

int main(){
    vector<int> arr = {6,3,5,2,7};
    cout<<bruteInverse(arr);
    return 0;
}