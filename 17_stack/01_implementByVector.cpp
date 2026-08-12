#include<iostream>
#include<vector>
using namespace std;

//Revision Day 89 [12/08/2026]

/*
    LeetCode 225, 232 : Implement stack using Queue and vice-versa

    Topic : Stack Implementation using Vector

    A Stack is a linear data structure that follows
    LIFO (Last In, First Out) principle.

    Implemented:

    1. push()   - Insert element at the top
    2. pop()    - Remove element from the top
    3. top()    - Access the top element
    4. empty()  - Check whether stack is empty

    Key Point:
    The last element of the vector acts as the top of the stack.

    Edge Cases:

    * Empty stack
    * Single element
    * Multiple elements

    Time Complexity:
    push()  : O(1)
    pop()   : O(1)
    top()   : O(1)
    empty() : O(1)

    Important:
    Stack follows LIFO:
    The element inserted last is removed first.

    Example:
    Push: 10 → 20 → 30
    Pop : 30 → 20 → 10
*/


class Stack{

    vector<int> v;

public:

    void push(int val){     //O(1)
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        //return v[v.size()-1];

        if(v.empty()) return -1;

        return v.back();
    }

    bool empty(){
        return v.size() == 0;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}