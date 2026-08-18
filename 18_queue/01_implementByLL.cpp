#include<iostream>
#include<queue>
using namespace std;

//Revision Day 95 [18/08/2026]

/*
    LeetCode 933 - Number of Recent Calls

    Topic: Queue Implementation using Linked List

    Implemented:
    1. push()   -> Insert element at the rear/tail
    2. pop()    -> Remove element from the front/head
    3. front()  -> Return front element
    4. empty()  -> Check whether queue is empty

    Key Concept:
    Queue follows FIFO (First In, First Out).

    Structure:
    head -> Front of Queue
    tail -> Rear of Queue

    Time Complexity:
    push()  -> O(1)
    pop()   -> O(1)
    front() -> O(1)
    empty() -> O(1)

    Space Complexity:
    O(n)

    Important:
    When the last node is removed, both head and tail
    should be set to NULL.
*/

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }  
};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = tail = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);

        if(empty()){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(empty()){
            cout<<"Queue is empty ";
            return;
        }
        Node* temp = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }
        delete temp;
    }

    int front(){
        if(empty()){
            cout<<"Queue is empty ";
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){

    Queue q;
    //queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}