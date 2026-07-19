#include<iostream>
using namespace std;

//Revision Day 64

/*
    LeetCode 231, 326, 342 : Power of two, three, four

    Topic: Recursion - Factorial

    Time Complexity: O(n)
    Space Complexity: O(n)  // due to recursive call stack

    Key Learning:
    1. Base case: factorial(0) = 1.
    2. Each recursive call computes n * factorial(n-1).
    3. The recursion unwinds after reaching the base case.
    4. Demonstrates the fundamental structure of recursion:
    -> Base Case
    -> Recursive Case
    5. Suitable for learning recursion, but iterative approach is preferred
       for very large n to avoid stack overflow.
*/

int fact(int n){
    if(n == 0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    cout<<"Factorial "<<fact(5)<<endl;
    return 0;
}