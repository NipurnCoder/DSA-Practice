#include<iostream>
#include<vector>
using namespace std;

//Revise today 02/05

//function store vec, tar

int linear_search(vector<int>vec, int target)
{
   // int ans=0;
    for(int i=0;i<vec.size();i++)

    {
        //if target is find return idx
        if(vec[i]==target)
           // ans=vec[i];
            return i;
    }
     return -1;
}

int main()
{
    vector<int>vec = {45,67,89,90,23};
    int target=90 ;

    //function call
    int index=linear_search(vec,target);

    //loop for print idx
    if(index!= -1)
    {
        cout<<"Element found at index "<<index<<endl;
    }
    else{
        cout<<"ELement NOT Found !! "<<index<<endl;
    }

    return 0;
}