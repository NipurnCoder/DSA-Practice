#include <iostream>
using namespace std;

// Revision Day 44

/*
    LeetCode 1281 : Substract the Product and Sum of the Digit of an Integer
    Leetcode 7 : Reverse Integer

    Amstrong Number

    153 = 1³ + 5³ + 3³ = 153

    Time Complexity - O(digit)
    Space Complexity - O(1)

*/


bool isArmstrong(int n){
    int copyN = n;
    int sumOfCubes = 0;

    while(n != 0){
        int digit = n % 10;
        sumOfCubes += (digit*digit*digit);
        n = n/10;
    }
    return (copyN == sumOfCubes);
}

int main(){

    int n = 153;

    if(isArmstrong(n)){
            cout<<"It is Armstrong Number "<<endl;
        }
        else{
            cout<<"Not Armstront Number ! "<<endl;
        }

    return 0;
}