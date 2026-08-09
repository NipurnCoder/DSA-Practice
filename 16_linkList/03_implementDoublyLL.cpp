#include<iostream>
using namespace std;

//Revision Day 86

/*
    LeetCode 430 : Flatten a Multilevel Doubly Linked List
             707 : Design Linked List

    Topic: Doubly Linked List (DLL):
        A linked list where each node contains data, 
        a pointer to the next node, and a pointer to the previous node, 
        allowing traversal in both directions.

    Implemented:                                        Time Complexity:
    1. push_front() - Insert node at the beginning.         O(1)
    2. push_back()  - Insert node at the end.               O(1)
    3. pop_front()  - Delete node from the beginning.       O(1)
    4. pop_back()   - Delete node from the end.             O(1)
    5. print()      - Traverse and display the DLL.         O(n)

    Key Concept:
    Each node contains two pointers:
    next -> points to the next node
    prev -> points to the previous node

    Important:
    Always handle the empty list and single-node cases
    while performing insertion/deletion.
    
*/    

class Node{

public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{

private:
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
   }

   void print(){
    Node* temp = head;

        while(temp != NULL){
            cout<<temp->data <<" <=> ";
            temp = temp->next;
        } 
        cout<<"NULL\n";
   }

   void push_back(int val){
    Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
   }

   void pop_front(){
        if(head == NULL){
            cout<<"DLL is empty\n";
            return;
        }
        Node* temp = head;

        if(head == tail){       // Only one node
            head = tail = NULL;
        }
        else{
            head = head->next;
            head->prev = NULL;

            // temp->next = NULL;
            // delete temp;
        }

        delete temp;
   }

   void pop_back(){
        if(head == NULL){
            cout<<"DLL is empty \n";
            return;
        }
        Node*temp = tail;

        if(head == tail){       // Only one node
            head = tail = NULL;
        }
        else{
            tail = tail->prev;
            tail->next = NULL;

            // temp->prev = NULL;
            // delete temp;
        }

        delete temp;
   }
};

int main(){
    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.push_back(4);

    dll.pop_front();

    dll.pop_back();

    dll.print();

    return 0;
}