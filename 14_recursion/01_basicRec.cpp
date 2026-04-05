#include<iostream>
using namespace std;

void reverse(int n){
    if(n == 1){
        cout<<"1"<<endl;
        return;
    }

    cout<<n<<" ";
    reverse(n-1);
}

int main(){
    reverse(9);
    return 0;
}