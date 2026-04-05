#include<iostream>
using namespace std;

class Circular {
    int f;
    int r;
    int currSize;
    int *arr;
    int cap ;

public:
    Circular(int size){

        cap = size;
        int f = 0;
        int r = -1;
        arr = new int [cap];
        currSize = 0;
    }

    void push(int val){     //0(1)
        if(currSize == cap){
            cout<<"Is full !\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = val;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout<<"Is Empty !\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;     
    }

    int front(){
        if(empty()){
            cout<<"Is Empty !\n";
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

    void printArr(){
        for(int i=0; i<cap; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Circular c(3);

    c.push(1);
    c.push(2);
    c.push(3);
    //c.push(4);

    c.printArr();

    c.pop();
    
    c.push(4);
    
    c.printArr();


    while(!c.empty()){
        cout<<c.front()<<" ";
        c.pop();
    }
    cout<<endl;

    return 0;
}