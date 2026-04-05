#include<iostream>
#include<vector>
using namespace std;

class Solution {

public :
    int search(vector<int>& arr, int tar){
        int st=0, end = arr.size()-1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(arr[mid]==tar){
                return mid;
            }
            
            if(arr[st]<=arr[mid]){ //left
                if(arr[st]<=tar && tar<=arr[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                if(arr[mid]<=tar && tar <= arr[end]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            
        }
        return -1;
    }
};

int main(){
    //vector<int> arr = {3,4,5,6,7,0,1,2};
    vector<int> arr = {6,7,8,9,0,1,2,3,4,5};
    int tar=4;

    for(int val : arr){
        cout << val <<" ";
    }

    cout<<endl;

    Solution s;
    cout<< s.search(arr, tar);

    return 0;

}
