#include<iostream>
using namespace std;

//Revision Day 87

/*
    LeetCode 457 : Circular Array Loop

    Topic: Circular Linked List (CLL):
        A Circular Linked List is a linked list in which
        the last node points back to the first node (head) instead of pointing to NULL.

    Implemented:
    1. Insert at Head
    2. Insert at Tail
    3. Delete Head
    4. Delete Tail
    5. Print Circular List

    Key Point:
    tail->next always points to head.

    Edge Cases:
    - Empty list
    - Single node
    - Multiple nodes

    Time Complexity:
    Insert Head  : O(1)
    Insert Tail  : O(1)
    Delete Head  : O(1)
    Delete Tail  : O(n)
    Print        : O(n)

    Important:
    In a circular linked list, the last node does not point to NULL;
    it points back to the head.
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

class CircularList{
    Node* head;
    Node* tail;

public:
    CircularList(){
        head = tail = NULL; 
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;  //connected back
        }else{
            newNode->next = head;   //head = tail->next
            head = newNode;
            tail->next = head;
        }
    }

    void print(){
        if (head == NULL) return ;

        cout<<head->data<<"->";
        Node* temp = head->next;

        while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }

    void insertAtTail(int val){
       Node* newNode = new Node(val);

       if(tail == NULL){
        head = tail = newNode;
        tail->next = newNode;
       }
       else{
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
       }
    }

    void deleteHead(){
        if(head == NULL) return ;

        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail(){
        if(head == NULL) return ;

        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = tail;

            Node* prev = head;
           
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

};

int main(){
    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.print();

    cll.insertAtTail(5);
    cll.insertAtTail(6);

    cll.deleteHead();

    cll.deleteAtTail();
    cll.print(); 
    return 0;
}