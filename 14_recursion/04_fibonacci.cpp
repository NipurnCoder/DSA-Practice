#include<iostream>
using namespace std;

//Revision Day 66

/*
    LeetCode 1137 : N-th Tribonacci Number

    Learned recursive implementation of Fibonacci sequence.
    Practiced base cases and recursive relation:
    F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2).
    Understood recursion tree and overlapping subproblems.

    Time Complexity: O(2^n)
    Space Complexity: O(n) (recursion stack)
*/

int fibo(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}

int main(){
    cout<<fibo(6);
    return 0;
}