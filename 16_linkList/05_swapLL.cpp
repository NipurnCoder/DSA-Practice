#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Revision Day 88

/*
    LeetCode 24 : Swap Nodes in Pairs
            143 : Reorder List

    Topic: Linked List - Swap Nodes in Pairs

    Approach:
    1. Take two nodes at a time: first and sec.
    2. Store the next pair using third.
    3. Reverse the current pair by changing next pointers.
    4. Use prev to connect the previous swapped pair.
    5. Move first and sec to the next pair.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Point:
    Swap nodes by changing pointers, not their values.
    If the number of nodes is odd, the last node remains unchanged.
*/    

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int data){
        val = data;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        //Base Case
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* first = head; 
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while(first != NULL && sec != NULL){

            //Swap The Pairs
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;
        
            //Connect Previous Pairs
            if(prev != NULL){
                prev->next = sec;
            } else {
                head = sec;
            }

            //Move to Next Pairs
            prev = first;
            first = third;

            if(third != NULL){
                sec = third->next;
            } else{
                sec = NULL;
            }
        }
        return head;
    }
};


void print(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    //Create Linked List
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout<<"Original Linked List "<<endl;
    print(head);

    cout<<"After Swaping "<<endl;

    Solution s;
    head = s.swapPairs(head);
    print(head);

    return 0;
}