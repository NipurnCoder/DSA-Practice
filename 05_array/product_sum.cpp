#include<iostream>
using namespace std;

int product_array(int arr[], int size)
{
    int ans=1;
    for(int i=0;i<size;i++)
    {
        ans*=arr[i];
        // int mul=arr[i]*arr[i+1];
        // ans=mul*arr[i+1];
    }
    cout<<"Product array : "<<ans<<" "<<endl;
}
int sum_array(int arr[], int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    
    cout<<"Sum array : "<<sum<<endl;
}


int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size=6;

    product_array(arr,size);
    sum_array(arr,size);

    cout<<"product : "<<(1*2*3*4*5*6)<<endl;
    cout<<"Sum : "<<(1+2+3+4+5+6)<<endl;
}