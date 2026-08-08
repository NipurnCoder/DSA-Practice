#include<iostream>
using namespace std;

//Revision Day 85

/*
    LeetCode 206 : Reverse Liked List

    Topic: Singly Linked List - Reverse a Linked List

    Algorithm: Iterative 3-Pointer Approach

    Steps:
    1. Initialize prev = NULL and curr = head.
    2. Store curr->next in next before changing the link.
    3. Reverse the current node's link: curr->next = prev.
    4. Move prev and curr one step forward.
    5. After the loop, update head = prev.

    Key Point:
    Always store curr->next before reversing the link,
    otherwise the remaining list will be lost.

    Time Complexity: O(n)
    Space Complexity: O(1)
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

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    // Insert at end

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display list
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Reverse function
    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;   // store next
            curr->next = prev;   // reverse link
            prev = curr;         // move prev
            curr = next;         // move curr
        }

        head = prev; // update head
    }
};

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    cout << "Original List: ";
    ll.display();

    ll.reverse();

    cout << "Reversed List: ";
    ll.display();
}