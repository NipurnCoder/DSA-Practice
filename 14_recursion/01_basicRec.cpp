#include<iostream>
using namespace std;

//Revision Day 63 [18/7/2026]

/*
    LeetCode : 412 Fizz Buzz
         234 : Palindrome Linked List
    
    Topic: Recursion
    Problem: Print numbers in reverse order using recursion

    Concepts Covered:
    - Recursive function calls
    - Base case to stop recursion
    - Recursive case (self-call)
    - Call stack behavior
    - Time Complexity: O(n)
    - Space Complexity: O(n) (recursion stack)
*/

void reverse(int n){

    if(n == 1){
        cout<<"1"<<endl;
        return;
    }

    cout<<n<<" ";
    reverse(n-1);
}

int main(){

    reverse(9);
    return 0;
}