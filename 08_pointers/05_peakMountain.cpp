#include <iostream>
#include <vector>
using namespace std;

int linearSearch (vector<int>& arr){

    int n = arr.size();

    for(int i=1;i<=n-1;i++){
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            return arr[i];
        }
    }
    cout<<endl;
    return -1;
}

int binaryMountain (vector<int>& arr){

    int st=1, end=arr.size()-2;

    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }

        else if(arr[mid-1]<arr[mid]){ //increasing slope
            st=mid+1;  //right
        }

        else {
            end=mid-1;  //left
        }
    }
    return -1;
}

int main (){

    vector<int> arr = {0,3,8,9,5,2};

    for (int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    int ans ;
    ans= linearSearch(arr);

    int binaryAns=binaryMountain(arr);

    cout<<"Peak is : " << ans<<endl;
    cout<<"Peak by Binary search : "<<binaryAns;
    return 0;

}