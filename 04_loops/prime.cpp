#include<iostream>
using namespace std;

//Revision [6/11/2026]

/*
    Topic: Prime Number
    Approach: While Loop
    Logic:
    1. Prime number has exactly two factors: 1 and itself.
    2. Start checking divisors from i = 2.
    3. If n % i == 0, then n is NOT PRIME.
    4. Use i * i <= n to check divisors up to sqrt(n).
    5. If no divisor is found, n is PRIME.
    6. Numbers n <= 1 are NOT PRIME.

    Time Complexity: O(sqrt(n))
    Space Complexity: O(1)

    Important:
    - Use bool isprime to track the result.
    - Use break when a divisor is found.
    - Print the result outside the loop to avoid repeated output.
*/

int main()
{
    int n, i=2;
    bool isprime = true;

    cout<<"Enter your number : ";
    cin>>n;

    for(i; i*i <= n; i++){          //root is best for find prime number
        if(n % i == 0){
            isprime = false;
            break;
        }
    }

    if(isprime == true){
        cout<<"It is Prime number ";
    }
    else{
        cout<<"It is Non Prime number ";
    }

    // while(i<=(n-1))
    // {
    //     if(n%i==0)
    //     {
    //         cout<<"It is NOT PRIME ";
    //         break;
    //     }

    //     else
    //     {
    //         i+=1;
    //     }
    //      cout<<"It is PRIME ";
    // }
    
    return 0;       
}

