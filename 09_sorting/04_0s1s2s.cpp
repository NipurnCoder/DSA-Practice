#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bruteForce(vector<int> &num){  //TC=O(nlogn) SC=O(1)
    sort(num.begin(), num.end());
}

void optimised(int arr[], int n){ //optimied approach TC=O(n)

    int count0=0, count1=0, count2=0;

    for(int i=0;i<n;i++){
        if(arr[i]== 0) count0++;
        else if(arr[i]== 1) count1++;
        else count2++;
    }

    int idx = 0;

    for(int i=0;i<count0;i++){
        arr[idx++] = 0;
    }
    for(int i=0;i<count1;i++){
        arr[idx++] = 1;
    }
    for(int i=0;i<count2;i++){
        arr[idx++] = 2;
    }
}

void printVector(vector<int> &num){
    for(int i : num){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> num = {2,0,2,1,1,0,1,2,0,0};
    
    cout<<"BruteForce Approach : "<<endl;
    bruteForce(num);
    printVector(num);


    int n = 10;
    int arr[] = {2,0,2,1,1,0,1,2,0,0};

    cout<<"Optimised Approach : "<<endl;
    optimised(arr, n);
    printArray(arr, n);

    return 0;
}