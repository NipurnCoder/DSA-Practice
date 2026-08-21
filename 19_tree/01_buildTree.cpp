#include<iostream>
#include<vector>
using namespace std;

//Revision Day 98

/*
    LeetCode 144 : Binary Tree Preorder Traversal

    Topic: Binary Tree Construction using Preorder Traversal

    Implemented:
    1. Node class with data, left and right pointers
    2. buildTree() to construct a binary tree recursively
    3. Used -1 to represent NULL nodes
    4. Used a static index to traverse the preorder array

    Key Concept:
    Preorder Traversal = Root -> Left -> Right

    Example:
    {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

    Constructed Tree:
        1
       / \
      2   3
         / \
        4   5

    Important:
    - Every valid value creates a new Node.
    - -1 returns NULL.
    - Recursion first builds the left subtree, then the right subtree.
    - static idx keeps track of the current position during recursion.

    Complexity:
    Time: O(n)
    Space: O(h) recursion stack
    Tree Storage: O(n)
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);   //LEFT
    root->right = buildTree(preorder);  //RIGHT

    return root;
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4,-1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;

    return 0;
}