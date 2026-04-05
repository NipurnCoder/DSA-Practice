#include<iostream>
#include<vector>
using namespace std;

void countPrime(int n){
    vector<bool> isPrime(n+1, true);
        int count = 0;

        for(int i=2; i<n; i++){
            if(isPrime[i]){
                count++;

                for(int j=i*2; j<n; j=j+i){
                    isPrime[j] = false;
                }
            }
        }
    cout<< count<<endl;
}

int main(){

    int n;
    cout<<"Enter the no. ";
    cin>>n;
    cout<<endl<<"count of Prime numbers ";

    countPrime(n);

    return 0;
}