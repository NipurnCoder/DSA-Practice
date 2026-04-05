#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){ //O(n^2)

    for(int i=0;i<n;i++){
        bool isSwap = false;    //optimised
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void inputArray(){

}

int main (){
    int n = 5;
    int arr[] = {2,4,5,1,3};

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}