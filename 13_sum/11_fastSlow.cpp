#include<iostream>
#include<vector>
using namespace std;

//Revision Day 58

/*
    LeetCode 442 : Find All Duplicates in Array
    LeetCode 448 : Find All Numbers Disappeared in Array

    Topic:
    - Floyd's Cycle Detection (Tortoise & Hare)

    Key Concepts:
    - Treat array as a linked list
    - Slow pointer moves 1 step
    - Fast pointer moves 2 steps
    - Find meeting point inside the cycle
    - Reset slow to the start
    - Move both one step until they meet
    - Meeting point = Duplicate Number

    Complexity:
    - Time: O(n)
    - Space: O(1)

    Formula:
    Phase 1:
        slow = nums[slow]
        fast = nums[nums[fast]]

    Phase 2:
        slow = nums[0]
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

    Remember:
    Duplicate number creates a cycle in the array.

*/


int slowFast(vector<int> &arr){

    int slow = arr[0], fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    } 
    while(slow != fast);
    //reset slow to find another
    slow = arr[0];

    while(slow != fast){

        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main(){

    vector<int> arr = {3,1,3,4,2};
    cout<<slowFast(arr)<<endl;

    return 0;
}