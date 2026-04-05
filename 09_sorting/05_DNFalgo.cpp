#include<iostream>
using namespace std;

void dutchNationalFlage(int arr[], int n){ //O(n)
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++; low++;
        } else if(arr[mid] == 1){
            mid ++;
        } else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n =10;
    int arr[] = {2,0,2,1,1,0,1,2,0,0};

    dutchNationalFlage(arr, n);
    print(arr, n);

    return 0;
}