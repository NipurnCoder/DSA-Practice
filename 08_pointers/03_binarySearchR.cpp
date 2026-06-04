#include<iostream>
#include<vector>
using namespace std;

//Revision Day 21 [4/6/26]

/*
    LeetCode-704 :  Binary Search  

    Concept - Binary Seaech by Reccursion

    Time - O(log n)
    Space - O(log n)

    recBinarySearch(arr, 9, 0, 5)
            |
          mid=2
            |
        9 > 3
            |
            v
 recBinarySearch(arr, 9, 3, 5)
            |
          mid=4
            |
        arr[4]=9
            |
         return 4

*/

//Function
int recBinarySearch(vector<int>& arr, int tar, int st, int end){

    if(st<=end){
        //Calc mid
        int mid = st + (end-st)/2;

        //Right search
        if(tar>arr[mid]){
            return recBinarySearch(arr, tar, mid+1, end);
        }
        //Left search
        else if(tar <arr[mid]){
            return recBinarySearch(arr, tar, st, mid-1);        //recurcive
        }
        //target == mid
        else {
            return mid;
        }
    }
    return -1;
}

int main(){
    //sorted vector ASCE
    vector<int> arr = {-1, 0, 3, 5, 9, 12};

    int tar =9;
    int st=0;
    int n = arr.size();
    int end=n-1;

    cout<<tar<<" Found at idx : "<<recBinarySearch(arr,tar,st,end)<<endl;

    return 0;
}