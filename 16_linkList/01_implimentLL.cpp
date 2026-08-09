#include<iostream>
using namespace std;

//Revision Day 84 [07/08/2026]

/*
    LeetCode 203 : Remove Linked List Elements

    Topic: Singly Linked List (SLL):
        A linked list where each node contains data and a pointer to the next node, 
        allowing traversal in only one direction.

    Algorithm : Linked List Operations

    Operations:
    1. push_front() - Insert node at the beginning.
    2. push_back()  - Insert node at the end.
    3. pop_front()  - Delete the first node.
    4. pop_back()   - Delete the last node.
    5. insert()     - Insert node at a given position.
    6. search()     - Search for an element.
    7. reverse()    - Reverse using 3 pointers.
    8. middle()     - Find middle using Slow & Fast pointers.

    Key Point:
    Linked Lists use node pointers instead of indices.
    Always handle edge cases: Empty List & Single Node.

    Time      : O(1) - O(n) depending on operation
    Space     : O(1) auxiliary
    
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

    void push_front(int val){   //O(1)

        Node* newNode = new Node(val); //dynamic
        //Node newNode(val); //static-delete after the function runs

        if(head == NULL){
            head = tail = newNode;
            return;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){    //O(1)
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
    }    

    void pop_front(){   //O(1)
        if(head == NULL){
            cout<<"LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back(){    //O(n)
        if(head == NULL){
            cout<<"LL is empty\n";
            return;  
        }

        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){  //O(n)
        if(pos < 0){
            cout<<"invalid pos\n";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;

        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid pos\n";
                return;
            }
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"Invalid pos\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if(newNode->next == NULL){
            tail = newNode;
        }
    }

    void printll(){     //O(n)
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"--";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int search(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void reverse(){     //O(n)
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        tail = head;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void middle(){      //O(n)
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //return slow;
        cout<<slow->data<<endl;
    }
};

int main(){

    List ll;

    cout<<"Linked list "<<endl;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printll();

    cout<<"Push back"<<endl;
    ll.push_back(4);
    ll.printll();

    cout<<"Pop front element"<<endl;
    ll.pop_front();
    ll.printll();

    cout<<"Pop back element"<<endl;
    ll.pop_back();
    ll.printll();

    cout<<"Insert element in middle"<<endl;
    ll.insert(4, 1 ); //(val, pos)
    ll.printll();

    cout<<"Search element 1"<<endl;
    cout<<"At idx "<<ll.search(1)<<endl;

    cout<<"Reverse link list"<<endl;
    ll.reverse();
    ll.printll();

    cout<<"Middle of link list"<<endl;
    ll.middle();
    //ll.printll();

    return 0;
}