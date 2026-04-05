#include<iostream>
#include<string>
using namespace std;

void arrStr(){
    char str[] = "Hello Knowledge";
    int len = 0;

    for(int i=0; i<str[i] != 0; i++){ //for(int i=0;str[i] !='/o';i++)
        len++;
    }
    cout<< "length of string : "<<len<<endl;

    string s1 = "yo broo ";
    cout<<s1.length()<<endl;
    
    string s2 ;
    cout<<"enter "<<endl;
    getline(cin,s2);
    cout<<s2<<endl;
    
}

int main(){

    // char str[100];
    // cout<<"Enter char array : ";
    // //cin>>str;

    // cin.getline(str, 100, '.');

    // cout<<"Output is : "<<str<<endl;
    arrStr();
    return 0;
}