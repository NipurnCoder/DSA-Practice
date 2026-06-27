#include<iostream>
#include<vector>
using namespace std;

// Revision Day 43

/*
    LeetCode : 204 - Count Primes

    Sieve of Eratosthenes

    Approach:
    1. Assume all numbers are prime.
    2. Traverse from 2 to n-1.
    3. If a number is prime, increment count.
    4. Mark all its multiples as non-prime.

    Optimization:
    - Start marking from i*i instead of i*2.
    - Multiples smaller than i*i are already processed.

    Time Complexity  : O(n log log n)
    Space Complexity : O(n)

*/

void countPrime(int n){
    vector<bool> isPrime(n+1, true);
        int count = 0;

        for(int i=2; i<n; i++){
            if(isPrime[i]){
                count++;

                
                for(int j=i*2; j<n; j=j+i){ //int j=i*i; j<n; j=j+i
                    isPrime[j] = false;
                }
            }
        }
    cout<< count<<endl;
}

int main(){

    int n;
    cout<<"Enter the no. ";
    cin>>n;
    cout<<"Count of Prime numbers ";

    countPrime(n);

    return 0;
}