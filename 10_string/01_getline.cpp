#include<iostream>
#include<string>
using namespace std;

//Revision Day 35

/*
    LeetCode 58 : Length of last word
    
    Character Array & String Basics

    strlen for char array -> traverse until '\0'
    string.length() -> O(1)
    getline(cin, s) -> input with spaces
    cin.getline(arr, size, delimeter) -> char array input

    Time Complexity = O(n) manualy length
    Space Complexity = O(1)

*/

void arrStr(){

    char str[] = "Hello Knowledge";
    int len = 0;

    //calculate length 
    for(int i=0; str[i] != 0; i++){ //for(int i=0;str[i] !='/o';i++)
        len++;
    }
    cout<< "length of string : "<<len<<endl;

    //Claculate by inbuilt-function length
    string s1 = "yo broo ";
    cout<<s1.length()<<endl;
    
    //take input of string with space by using getline function
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