#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//Revision 46

/*
    LeetCode Practice:
        LC 7  - Reverse Integer
        LC 9  - Palindrome Number

    Reverse Integer & Palindrome Check

    Concepts Covered:
        1. Digit Extraction using %
        2. Number Reversal using / and %
        3. Integer Overflow Handling
        4. Palindrome Validation
        5. Handling Negative Numbers

    Formula:
        digit = n % 10
        reverse = reverse * 10 + digit
        n = n / 10

    Observation:
        A number is palindrome if:
        n == reverse(n)

        Negative numbers are not palindromes.

    Time Complexity:
        reverseNum()  : O(log n)
        isPalindrome(): O(log n)

    Space Complexity: O(1)
*/

int reverse(int n){

    int revNum = 0;

    while(n != 0){

        int dig = n % 10 ;

        //OverFlow Condition
        if(revNum > INT_MAX / 10 || revNum < INT_MIN / 10){
            return 0; 
        }

        revNum = revNum * 10 + dig;
        n = n/10;
    }

    return revNum;
}  

bool isPalindrom(int n){

    //Negative No = Non Reversable
    if(n < 0) 
        return false;

    int revNum = reverse(n);

    return n == revNum;
}

int main(){

    cout<<reverse(12321)<<endl;

    cout<<isPalindrom(-12321);

    return 0;
} 