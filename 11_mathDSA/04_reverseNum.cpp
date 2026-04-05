#include<iostream>
#include<algorithm>
using namespace std;

int reverse(int n){
    int revNum = 0;

    while(n != 0){
        int dig = n % 10 ;
        // if(revNum > INT16_MAX/10 || revNum < INT16_MIN /10){
        //     return 0; 
        // }
        revNum = revNum * 10 + dig;
        n = n/10;
    }
    cout<< revNum;
}  

bool isPalindrom(int n){
    if(n<0) return false;

    int revNum = reverse(n);
    return n == revNum;
}

int main(){
    reverse(23435);
    cout<<endl;
    isPalindrom(+23435);
    return 0;
} 