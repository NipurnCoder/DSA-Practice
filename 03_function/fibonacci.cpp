#include<iostream>
using namespace std;

int fibo(int n)
{
    int first=0, second=1;

    for(int i=0;i<n;i++)
    {
        cout<<first<<" ";
        int next = first+second;
        first=second;
        second=next;
    }
   // return 0;
}

int main()
{
    cout<<fibo(77);
    return 0;
}


// #include <iostream>
// using namespace std;

// int main() {
//     int n;

//     // Get number of terms from user
//     cout << "Enter the number of terms: ";
//     cin >> n;

//     // First two terms
//     int first = 0, second = 1;

//     cout << "Fibonacci Series: ";

//     for (int i = 0; i < n; i++) {
//         cout << first << " ";

//         // Generate next term
//         int next = first + second;
//         first = second;
//         second = next;
//     }

//     return 0;
// }
