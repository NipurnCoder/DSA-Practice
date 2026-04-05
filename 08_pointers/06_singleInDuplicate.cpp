#include <iostream>
#include <vector>
using namespace std;

int single(vector<int>& arr){

    int n = arr.size();
    int st=0 ,end = n-1;

    while(st <= end) {

        int mid = st + (end-st)/2;

        if(mid == 0 && arr[0] != arr[1]) return arr[mid];
        if(mid == n-1 && arr[n-1] != arr[n-2]) return arr[mid];

        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) return arr[mid];

        if(mid % 2 == 0) { //even
            if(arr[mid-1] == arr[mid]){ //left
                end = mid-1; //search in left
            }
            else { //right
                st = mid+1;
            }
        }
        else { //odd
            if(arr[mid-1] == arr[mid]){ //right
                st = mid+1; 
            }
            else { //left
                end = mid-1;
            }
        }
    }
}

 int inputArray(){
    
        int n;
        cout<<"Enter the size of Duplicate Array : ";
        cin>>n;
        int sz = n;
        int arr[sz];
        cout<<"Enter the element of dublicate array : ";
        for(int i=0;i<sz;i++){
            cin>>arr[i];
        }
        cout<<endl;

        cout<<"Your array is : ";
        for(int i=0;i<sz;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
    }

int main(){

    vector<int> arr = {1,1,2,2,3,3,4,8,8};

    for(int val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;

    int ans = single(arr);
    cout<<"The single element is : "<<ans<<endl;

    inputArray();
    int ans1 = single(inputArray);
    cout<<ans1;

    return 0;
}