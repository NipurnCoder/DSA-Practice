#include<iostream>
using namespace std;

// Revision [02/11/2026]

/*
    Topic: Sum of Natural Numbers
    Approach 1: Using for loop
    Approach 2: Mathematical Formula
    Formula: n * (n + 1) / 2
    Loop TC: O(n)
    Formula TC: O(1)
    SC: O(1)
    Key Point: Formula is faster because it calculates the sum directly.
    Important Note: Do not calculate the sum using both methods unnecessarily.
*/

int main() {
    int n, sum = 0;
    int count =  1;

    cout<<"Enter number upto print :";
    cin>>n;

    for(count;count<=n;count++)
    {
        sum+=count;
    }


    // while(count <= n)
    // {
    //     sum += count;
    //     count++;
    // }


    sum = n*(n+1)/2;
    
    cout<<"Sum of numbers from 1 to "<<n<<" is : "<<sum<<endl;

    return 0;
}

