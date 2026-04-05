#include<iostream>
using namespace std;

int kadanes(int arr[], int sz)
{
    int cs=0, maxs=INT_FAST16_MIN;

    for(int i=0;i<sz;i++)
    {
        cs+=arr[i];
        maxs=max(cs,maxs);

        if(cs<0)
        {
            cs=0;
        }
    }
    cout<<maxs<<endl;
}

int main()
{
    int arr[]={3,-4,5,4,-1,7,-8};
    int sz=7;

    kadanes(arr,sz);
}