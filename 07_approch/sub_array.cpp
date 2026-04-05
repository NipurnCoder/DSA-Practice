#include<iostream>
using namespace std;

int sub_array(int arr[], int size) {

    // for(int start=0;start<size;start++){
    //     for(int end=start;end<size;end++){
    //         for(int i=start;i<=end;i++){
    //             cout<<arr[i]<<" ";

    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(int);

    sub_array(arr,size);
}