#include<iostream>
using namespace std;

void inserstionSort(int arr[], int n){  //O(n^2)
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]<=curr){      // <---------Ascending or Decending
            arr[prev +1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void printArray(int arr[], int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cout<<"Enter size : ";
    cin>>n;

    cout<<"Enter the elements : ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl<<"Sorted array : ";

    // int n = 5;
    // int arr[]= {4,3,5,1,2};

    inserstionSort(arr, n);
    printArray(arr, n);

    return 0;
}