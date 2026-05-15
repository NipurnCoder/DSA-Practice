#include<iostream>
using namespace std;

//Revise this approach today

int intersect(int arr1[], int size1 ,int arr2[], int size2) //2 different Arrays of diff sizes
{
    cout<<"Intersected elements are ---"<<endl;     

    for(int i=0;i<size1;i++)    //loop 1 in arr1
    {
        for(int j=0;j<size2;j++) //loop 2 in arr2
        {
            if(arr1[i]==arr2[j])    //Common Elements or same elements
            {
                cout<<arr1[i]<<" ";     //print element
                break;
            }
        }
    }
    cout<<endl;
}

int main()
{
    int arr1[]={45,67,89,90,34};    //array initialization
    int size1=5;

    int arr2[]={89,90,54,65,45,12};
    int size2=6;

    intersect(arr1, size1, arr2, size2);    //function call

    return 0;
}