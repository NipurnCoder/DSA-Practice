#include<iostream>
using namespace std;

int intersect(int arr1[], int size1 ,int arr2[], int size2)
{
    cout<<"Intersected elements are ---"<<endl;

    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                cout<<arr1[i]<<" ";
                break;
            }
        }
    }
    cout<<endl;
}

int main()
{
    int arr1[]={45,67,89,90,34};
    int size1=5;

    int arr2[]={89,90,54,65,45,12};
    int size2=6;

    intersect(arr1, size1, arr2, size2);
}