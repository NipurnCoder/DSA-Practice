#include<iostream>
using namespace std;

//Revise this approach Today 

int main()
{
    int size=8, index=-1;
    int arr[size] = {9,8,5,7,2,0,3,1};  //array initialise with the size

    cout<<"The Array is : ";    //update code 
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int n;
    cout<<"Enter the element from array : ";
    cin>>n;
   
    for(int i=0; i<size; i++){
        if(arr[i] == n){
            cout<<"At index : "<<i<<endl;
        }
        else{
            continue;
        }
    }
    // for(int i=0;i<size;i++)
    // {
    //     if(arr[i]==3)
    //     {
    //       index=i;
    //       break;
    //     }
    // }

    // return index;


    // for(int i=0;i<size;i++)
    // {
    //     if(arr[i]==4)
    //     {
    //         index=i;
    //         //cout<<arr[i]<<index<<endl;
    //         break;
    //     }

        // else
        // {
        //     index=-1;
        //     cout<<"Not Found !!"<<index<<endl;

        // }
        //cout<<arr[i]<<index<<endl;
        
    // }
    //  if(index!=-1)
    //     {
    //         cout<<"Element is found at index "<<index<<endl;
    //     }

    //     else
    //     {
    //         cout<<"Not Found !!"<<index;

    //     }
    
     return 0;
}
