#include<iostream>
using namespace std;

int main(){
/*
    - AND (&): Returns 1 if both corresponding bits are 1.
    - OR (|): Returns 1 if at least one corresponding bit is 1.
    - XOR (^): Returns 1 if corresponding bits are different.
    - Left Shift (<<): Shifts bits to the left.
    - Right Shift (>>): Shifts bits to the right.
*/

    cout<<(6 | 10)<<endl; // OR
    cout<<(6 ^ 10)<<endl; // XOR
    cout<<(6 & 10)<<endl; // AND

    cout<<(6 << 10)<<endl; // LS
    cout<<(6 >> 10)<<endl; // RS
}