#include<iostream>
using namespace std;

int fact(int n){

    if(n == 0 || n == 1) return 1;

    return n * fact(n-1);
}

int main()
{

    cout<<fact(5);

    int n, i=1, fact=1 ;

    cout<<"Enter your number : ";
    cin>>n;

    for(i;i<=n;i++)
    {
        fact = fact*i;
    }

    cout<<"factorial of "<<n<<" is : "<<fact<<endl;

    // if(n==0&&1)
    // {
    //     fact=1;
    //     cout<<"Factorial of "<<n<<" is "<<fact<<endl;

    // }

    // else
    
    // if(n>=fact)
    // {    
    //     fact = fact*(n-1);

    //     cout<<"Factorial of "<<n<<" is : "<<fact<<endl;
    // }

   // cout<<(1*2*3*4*5*6*7);


    return 0;
}