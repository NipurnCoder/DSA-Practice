#include<iostream>
using namespace std;

int max_arr(int arr[],int sz){

    int maxSum= INT16_MIN;

    for(int st=0;st<sz;st++){
        int sum=0;
        for(int end=st;end<sz;end++){
            sum+=arr[end];
            maxSum = max(sum,maxSum);
        }
    }
    cout<<"Maximum sum of Array is : "<<maxSum<<endl;
}

int main(){

    int arr[] = {3,-4,5,4,-1,7,-8};
    int sz = sizeof(arr)/sizeof(int);
    cout<<"Array Is "<<endl;

    for(int i=0;i<sz;i++){
        cout<<"("<<arr[i]<<") ";
    }
    cout<<endl;
    max_arr(arr,sz);

}