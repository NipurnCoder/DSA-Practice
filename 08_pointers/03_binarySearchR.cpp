#include<iostream>
#include<vector>
using namespace std;

int recBinarySearch(vector<int>& arr, int tar, int st, int end){
    if(st<=end){
        int mid = st + (end-st)/2;

        if(tar>arr[mid]){
            return recBinarySearch(arr, tar, mid+1, end);
        }
        else if(tar <arr[mid]){
            return recBinarySearch(arr, tar, st, mid-1);        //recurcive
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int tar =3;
    int st=0;
    int n = arr.size();
    int end=n-1;

    cout<<recBinarySearch(arr,tar,st,end)<<endl;
    return 0;
}