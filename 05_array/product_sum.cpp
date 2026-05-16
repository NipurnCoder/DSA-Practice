#include<iostream>
using namespace std;

//Revise this approach today

int product_array(int arr[], int size)  //Function 1
{
    int ans=1;      //initialise the ans with value 1

    for(int i=0;i<size;i++)
    {
        ans*=arr[i];    //calculate the product of each element of array

        // int mul=arr[i]*arr[i+1];     another way to calculate by a variable mul
        // ans=mul*arr[i+1];
    }
    cout<<"Product array : "<<ans<<" "<<endl;
}

int sum_array(int arr[], int size)  //Function 2
{
    int sum=0;

    for(int i=0;i<size;i++)
    {
        sum+=arr[i];    //Calculate the Sum of each element in array
    }
    
    cout<<"Sum array : "<<sum<<endl;
}


int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size=6;

    product_array(arr,size); //function call 1
    sum_array(arr,size);    //function call 2

    cout<<"product : "<<(1*2*3*4*5*6)<<endl;    //calculate manually
    cout<<"Sum : "<<(1+2+3+4+5+6)<<endl;

    return 0;
}