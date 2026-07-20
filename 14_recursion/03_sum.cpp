#include<iostream>
using namespace std;

//Revision Day 65

/*
    LeetCode 70 : Climbind Stairs [TLE]
            779 : k-th Symbol in Grammar

    Topic: Recursion
    Problem: Sum of First N Natural Numbers

    Time Complexity: O(n)
    Space Complexity: O(n) (recursive call stack)

    ✔ Learned:
    - Base case stops recursion when n == 1.
    - Each recursive call adds the current number to the sum of previous numbers.
    - The recursion unfolds after reaching the base case.
    - Formula followed: sum(n) = n + sum(n-1).
*/    

int sum(int n){

    if(n == 1){
        return 1;
    }

    return n + sum(n-1);
}

int main(){

    cout<<sum(5)<<endl;
    return 0;
}