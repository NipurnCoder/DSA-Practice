#include<iostream>
using namespace std;

int unique_num (int arr[], int size)
{
    cout<<"Unique elements are "<<endl;
    for(int i=0;i<size;i++)
    {
        int count=0;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }

        if(count==1)
        {
            cout<<arr[i]<<" ";
        }

        // if(arr[i]!=arr[start])
        // {
        //     start++;
        // }
        // else if(arr[i]==arr[start])
        // {
        //     continue;
        // }
    }
    cout<<endl;
    // cout<<arr[unique]<<endl;
}

int main()
{
    int arr[] = {1,2,3,4,5,1,2};
    int size=7;

    unique_num(arr,size);

}