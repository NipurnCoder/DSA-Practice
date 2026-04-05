#include<iostream>
#include<vector>
using namespace std;

int reverse_vec(vector<int>&vec)
{
    int start=0, end=vec.size()-1;  //two pointer approch

    while(start<end)
    {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> vec = {34,56,78,98,12};
    for(int i: vec){
        cout<<i<<" ";
    }
    cout<<endl<<"Reverse is \n";

    reverse_vec(vec);
    for(int i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}