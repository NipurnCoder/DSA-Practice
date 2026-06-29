#include<iostream>
using namespace std;

//Revision Day 45

/*
    LeetCode Practice:
        LC 1979 - Find Greatest Common Divisor of Array
        LC 1071 - Greatest Common Divisor of Strings
        LC 365  - Water and Jug Problem

    GCD & LCM using Euclidean Algorithm

    Concepts Covered:
        1. Iterative GCD (Euclidean Algorithm)
        2. Recursive GCD
        3. LCM using GCD

    Formula:
        GCD(a, b) = GCD(b, a % b)
        LCM(a, b) = (a * b) / GCD(a, b)

    Time Complexity:
        gcd()    : O(log(min(a, b)))
        gcdRec() : O(log(min(a, b)))
        lcm()    : O(log(min(a, b)))

*/

//Greatest Common Divisor
int gcd(int a, int b){
    while(a>0 && b>0){
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if(a == 0) return b;
    return a;
}

//By Recurrsion
int gcdRec(int a, int b){
    if(b == 0) return a;
    return gcdRec(b, a % b);
}

//Lowest Common Multiple
int lcm(int a, int b){      //LCM
    int gcd = gcdRec(a, b);
    return (a*b)/gcd;
}

int main(){
    cout<<gcd(36, 144)<<endl;
    cout<<gcdRec(20, 24)<<endl;
    cout<<lcm(20,28)<<endl;
    return 0;
}