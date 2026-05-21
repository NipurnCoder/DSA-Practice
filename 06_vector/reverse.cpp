#include<iostream>
#include<vector>
using namespace std;

//Revise today 21/05

//function to revese
int reverse_vec(vector<int>&vec)
{
    int start=0, end=vec.size()-1;  //two pointer approch
    //2 ptr st/end

    //base condition
    while(start<end)
    {
        //in-build swap fn
        swap(vec[start], vec[end]);
        //update st/end
        start++;
        end--;
    }
}

int main()
{
    vector<int> vec = {34,56,78,98,12};
    //original vector
    for(int i: vec){
        cout<<i<<" ";
    }
    cout<<endl<<"Reverse is \n";

    //after reverse
    reverse_vec(vec);
    for(int i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}