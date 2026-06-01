#include<iostream>
using namespace std;

//Revision Day 18

/*
    LeetCode - 50 :  Pow(x, n)

    Approach - BinaryExponent (Fast Power)

    Repeatedly square the base and reduce the exponent by half.
    If the current exponent is odd, multiply the answer by the base.
    For negative powers, convert x^(-n) into (1/x)^n.
    
    Time - O(log n)
    Space - O(1)

*/

double exponantial_pow(double x, int n){

    //use long and double to store big sizes safely
    long bn = n;
    double ans = 1;

    //handel negative power
    if(bn < 0){
        //reciprocal of x
        x = 1/x;
        //make bn positive
        bn = -bn;
    }

    //handel positive power
    while(bn > 0){

        //odd exponent
        if(bn % 2 != 0){    //(bn%2 == 1)
            //add one x extra
            ans *= x;
        }
        x *= x;
        bn /= 2;
    }
    return ans;
}

int main(){

    //negative odd power
    double m = exponantial_pow(2,-3);
    cout<< m<<endl;

    //positive even power
    cout<<"Power(2^10) = "<< exponantial_pow(2,10)<<endl;

    return 0;
}