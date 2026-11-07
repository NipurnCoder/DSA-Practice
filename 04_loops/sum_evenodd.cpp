#include<iostream>
using namespace std;

// Revision [07/11/2026]

/*
    Topic: Sum of Even and Odd Numbers
    Approach: While Loop

    Logic:
    1. Initialize i = 1, evensum = 0, oddsum = 0.
    2. Run the loop while i <= a.
    3. If i % 2 == 0, add i to evensum.
    4. Otherwise, add i to oddsum.
    5. Increment i in every iteration.

    Important Points:
    - i % 2 == 0 checks whether i is even.
    - else handles odd numbers.
    - evensum += i means evensum = evensum + i.
    - oddsum += i means oddsum = oddsum + i.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Note:
    Always check the current number i, not the input a.
*/

int main(){

    int a, i=1, evensum=0, oddsum=0;

    cout<<"Enter the number : ";
    cin>>a;

    while(i <= a){

        if(i % 2 == 0){
            cout<<i<<endl;
            evensum += i;
        }
        // else if(a % 2 != 0){
        else{
            //cout<<i<<endl;
            oddsum += i;
        }

        i++;     
    }    

    cout<<"Sum of even numbers is : "<<evensum<<endl;
    cout<<"Sum of Odd numbers is : "<<oddsum<<endl;

    return 0;
}    