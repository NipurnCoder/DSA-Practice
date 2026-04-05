#include <iostream>
using namespace std;
int i=1, n;
int check_pow2 () {

    cout<<"Enter the number you want to find the power of 2 by me : ";
    cin>>n;

    while(i<n){
        i=i<<1;
    }

        if(n==i){
            cout<<n<<" is power of 2"<<endl;
        }
        else{
            cout<<n<<" is NOT power of 2"<<endl;
        }
        return 0;
}
int main()
{
    int a;
    cout<<"Enter your number : ";
    cin>>a;

    for(int i=0;i<=a;i++)
    {
        // if(i<=a)
        {
            cout<<check_pow2()<<endl;
        }

    }
}
    
//     cout<<check_pow2()<<endl;
//     cout<<check_pow2()<<endl;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;

//     if (n <= 0) {
//         cout << n << " is not a power of 2." << endl;
//         return 0;
//     }

//     int i = 1;
//     bool isPower = false;

//     while (i <= n) {
//         if (i == n) {
//             isPower = true;
//             break;
//         }
//         i = i << 1; // multiply i by 2
//     }

//     if (isPower)
//         cout << n << " is a power of 2." << endl;
//     else
//         cout << n << " is not a power of 2." << endl;

//     return 0;
// }
