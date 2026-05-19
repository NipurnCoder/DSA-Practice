#include<iostream>
using namespace std;

//Revise today 19/05

//function
int unique_num (int arr[], int size)
{
    cout<<"Unique elements are : ";

    //loop 1
    for(int i=0;i<size;i++)
    {
        //initialise count
        int count=0;
        //loop 2
        for(int j=0;j<size;j++)
        {
            //if val is same
            if(arr[i]==arr[j])
            {
                count++; //increase count
            }
        }

        //only one element same
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

    //Function call
    unique_num(arr,size);

    return 0;

}