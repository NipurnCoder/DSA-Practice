#include<iostream>
using namespace std;

double exponantial_pow(double x, int n){

    long bn = n;
    double ans = 1;

    if(bn<0){
        x = 1/x;
        bn = -bn;
    }

    while(bn>0){
        if(bn%2==1){
            ans *= x;
        }
        x*= x;
        bn /=2;
    }
    return ans;
}

int main(){
    double m = exponantial_pow(2,-10);
    cout<< m<<endl;

    cout<<"Power(2^10) = "<< exponantial_pow(2,10)<<endl;

    return 0;
}