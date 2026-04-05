#include<iostream>
#include<vector>
#include<list>
using namespace std;

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* first = head; 
//         ListNode* sec = head->next;
//         ListNode* prev = NULL;

//         while(first != NULL && sec != NULL){
//             ListNode* third = sec->next;
//             sec->next = first;
//             first->next = third;
        
//             if(prev != NULL){
//                 prev->next = sec;
//             } else {
//                 head = sec;
//             }

//             prev = first;
//             first = third;

//             if(third != NULL){
//                 sec = third->next;
//             } else{
//                 sec = NULL;
//             }
//         }
//         return head;
//     }
// };

void middle(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //return slow;
        cout<<slow->data<<endl;
    }