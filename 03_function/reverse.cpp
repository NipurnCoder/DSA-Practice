#include<iostream>
using namespace std;

/*
    Revision:[30/10/2026] 
        Reverse an Integer
    Topic: Loops, Functions, Modulus and Division
    Approach: Extract digits from right to left
    Time Complexity: O(log10(n)) for n > 0
    Space Complexity: O(1)

    Key Points:
    1. n % 10 extracts the last digit.
    2. ans * 10 shifts the digits left by one position.
    3. n / 10 removes the last digit.
    4. The loop stops when n becomes 0.
*/


int rev(int n)
{
    int ans=0, rem;
    
    
       for(;n!=0;n/=10)
        {
            rem=n%10;
            ans=ans*10+rem;

            // rem=n%10;
            // num=(ans+rem);
            // ans=(num*10);
            // n/=10;
            //break;
        }
    return ans;
}

int main ()
{
    cout<<rev(6789)<<endl;
}

