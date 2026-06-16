#include<iostream>
using namespace std;

//Revision Day 32

/*
    LeetCode 75 : Sort Colors

    Dutch National Flag Algorithm

        Idea:
       - Sort array containing only 0s, 1s and 2s
       - low -> boundary of 0s
       - mid -> current element
       - high -> boundary of 2s

        0 ... low-1      -> all 0s
        low ... mid-1    -> all 1s
        mid ... high     -> unsorted
        high+1 ... n-1   -> all 2s

       Time Complexity = O(n)
       Space complexity = O(1)
       
*/

void dutchNationalFlage(int arr[], int n){ //O(n)

    int low = 0, mid = 0, high = n-1;

    while(mid <= high){

        //Place 0 in the left region.
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++; low++;

        }//1 is already in the correct middle region.
        else if(arr[mid] == 1){
            mid ++;

        }//Place 2 in the right region.
        else{ //mid == 2
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

void print(int arr[], int n){

    for(int i=0; i<n; i++){
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