#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Revision Day 90 [13/08/2026]

/*
    LeetCode 739 : Daily Temperatures
             844 : Backspace String Compare

    Topic: Stack Implementation using STL List

    Stack follows LIFO (Last In, First Out).

    Implemented:
    1. push()  -> Insert element at front       O(1)
    2. pop()   -> Remove element from front     O(1)
    3. top()   -> Get front element             O(1)
    4. empty() -> Check whether stack is empty  O(1)

    Key Point:
    Using list's front as the stack top allows
    push and pop operations in O(1) time.

    Example:
    push(11), push(22), push(33)
    Output: 33 22 11

    Space: O(n)
*/    

class Stack{
    list<int> ll;

public:
    void push(int val){     //O(1)
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }
};

int main(){

    Stack s;

    s.push(11);
    s.push(22);
    s.push(33);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}