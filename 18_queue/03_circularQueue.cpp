#include<iostream>
using namespace std;

//Revision Day 97

/*
    Related LeetCode:
    LeetCode 622 - Design Circular Queue

    Topic: Circular Queue Implementation using Array

    Implemented:
    1. push()   -> Insert element at the rear
    2. pop()    -> Remove element from the front
    3. front()  -> Return front element
    4. empty()  -> Check whether queue is empty
    5. printArr() -> Display the array elements

    Circular Queue : Follows FIFO (First In, First Out).
        The rear and front move circularly using:
        (index + 1) % capacity

    Structure:
    f -> Front of Queue
    r -> Rear of Queue
    currSize -> Current number of elements

    Time Complexity:
    push()   -> O(1)
    pop()    -> O(1)
    front()  -> O(1)
    empty()  -> O(1)

    Space Complexity:
    O(n)

    Important:
    When rear reaches the last index, it wraps around
    to index 0 using modulo (%).

    Also revised variable shadowing:
    Use f = 0 and r = -1 instead of
    int f = 0 and int r = -1 inside the constructor.
*/

class Circular {
    int f;  //front
    int r;  //rear
    int currSize;
    int *arr;
    int cap ; //capacity - maximum number of elements the queue can hold.

public:
    Circular(int size){

        cap = size;

        //int f = 0, r = -1; local variable -> shadows class member 
        f = 0;
        r = -1;
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