#include<iostream>
#include<vector>
using namespace std;

//Revise Binary Search today

int binarySearch(vector<int> arr, int tar){
    int st=0, end=arr.size()-1;     //Two pointers approach

    while(st<=end){
        //int mid = (st+end)/2; //This might overflow
        int mid = st+(end-st)/2;
        cout<<"mid is: "<<arr[mid]<<endl; 
        
        //Array is already sorted in ascending order

        if(tar > arr[mid]){     //search in left 
            st = mid+1; //2nd half
        }
        else if(tar < arr[mid]){    //search in right
            end = mid-1; //1st half
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12}; //even
    //vector<int> arr = {-1, 0, 3, 5, 9, 12}; //odd
    int tar;

    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Enter the target value : ";
    cin>>tar;

    cout<<"Target value "<< tar<<" Found at index = "<<binarySearch(arr, tar)<<endl;

    return 0;
}

 