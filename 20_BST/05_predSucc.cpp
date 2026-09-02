#include<iostream>
#include<vector>
using namespace std;

//Revision Day 110 [2/09/2026]

/*
    LeetCode 687 : Longest Univalue Path
             110 : Balanced Binary Tree
             669 : Trim a Binary Search Tree

    Topic: Find Predecessor & Successor in BST

    Approach:
        1. Use BST properties to search for the key.
        2. If key < curr->data:
            → curr can be a possible Successor.
            → Move to the left subtree.
        3. If key > curr->data:
            → curr can be a possible Predecessor.
            → Move to the right subtree.
        4. If the key is found:
            → Predecessor = rightmost node of left subtree.
            → Successor = leftmost node of right subtree.
        5. If predecessor/successor does not exist, return -1.

    Complexity:
        Time  : O(h), where h = height of BST
        Space : O(1)

    Key Point:
        Inorder predecessor = largest value smaller than key.
        Inorder successor   = smallest value greater than key.
*/

class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

// Find Predecessor & Succesor in BST

Node* rightMostInleftSubtree(Node* root){
    Node* ans;

    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root){
    Node*ans;

    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root, int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data){
            pred = curr;
            curr = curr->right;
        } else{
            if(curr->left != NULL){
                //inorder predecessor
                pred = rightMostInleftSubtree(curr->left);
            }
            if(curr->right != NULL){
                //inorder succesor
                succ = leftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    //return {pred->data, succ->data};
    return { 
        pred ? pred->data : -1,
        succ ? succ->data : -1
    }; 
}

int main(){

    Node* root =new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;

    vector<int> ans = getPredSucc(root, key);
    cout<<"Predecessor : "<<ans[0]<<endl;
    cout<<"Succesor : "<<ans[1]<<endl;

    return 0;
}