#include<iostream>
using namespace std;

//Revision [03/11/2026]

/*
    Topic: While Loop
    Problem: Print all even numbers from 1 to n and calculate their sum
    
    Approach:
        1. Initialize i = 1 and evensum = 0.
        2. Run the while loop until i <= n.
        3. Check if i is even using i % 2 == 0.
        4. Print the even number and add it to evensum.
        5. Increment i by 1.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Points:
        - % is the modulus operator.
        - evensum += i is equivalent to evensum = evensum + i.
        - i++ updates the loop variable.
        - This code calculates the sum of even numbers, not the sum of all numbers.
*/

int main(){

    int a, i = 1, evensum = 0;
    cout<<"Enter the number : ";
    cin>>a;


    while(i <= a){
        if(i % 2 == 0){
            cout<<i<<endl;
            evensum += i;
        }
        i++;
    }    

    cout<<"Sum is :"<<evensum<<endl;


    // if(a % 2 == 0)
    // {
    //     cout<<"Your number is EVEN ";
    // }

    // else
    // {
    //     cout<<"Your number is ODD ";
    // }

    return 0;
}