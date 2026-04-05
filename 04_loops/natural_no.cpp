#include<iostream>
using namespace std;

int main()
{
    int n, sum=0;
    int count=1;

    cout<<"Enter number upto print :";
    cin>>n;

    // for(count;count<=n;count++)
    // {
    //     sum+=count;
    // }


    while(count<=n)
    {
        sum+=count;
        count++;
    }


    //sum = n*(n+1)/2;
    
    cout<<"Sum of numbers from 1 to "<<n<<" is : "<<sum<<endl;

    return 0;
}

