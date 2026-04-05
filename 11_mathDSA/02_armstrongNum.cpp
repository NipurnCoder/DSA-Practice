#include <iostream>
using namespace std;

bool isArmstrong(int n){
    int copyN = n;
    int sumOfCubes = 0;

    while(n != 0){
        int digit = n % 10;
        sumOfCubes += (digit*digit*digit);
        n = n/10;
    }
    return (copyN == sumOfCubes);
}

int main(){

    int n = 153;

    if(isArmstrong(n)){
            cout<<"It is Armstrong Number "<<endl;
        }
        else{
            cout<<"Not Armstront Number ! "<<endl;
        }

    return 0;
}