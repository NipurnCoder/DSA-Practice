#include<iostream>
#include<vector>
using namespace std;

//Revision Day 102

/*
    LeetCode 102 : Level Order Traversal

    Topic: Print Nodes at K-th Level of Binary Tree

    Key Concepts:
    1. Used recursion to traverse the binary tree.
    2. Root is considered Level 1.
    3. Decrease k by 1 whenever moving to the next level.
    4. When k == 1, print the current node.
    5. If root == NULL, return to stop recursion.

    Function:
    KthLevel(root, k)
    → Traverse left and right subtrees recursively.
    → Print all nodes present at the K-th level.

    Time Complexity: O(n) in worst case
    Space Complexity: O(h), where h = height of tree

    Key Takeaway:
    "Move down → k-- ; k == 1 → print node"
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
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void KthLevel(Node* root, int k){
    if(root == NULL){
        return ;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return ;
    }
    KthLevel(root->left, k-1);
    KthLevel(root->right, k-1);
}

int main(){
    vector<int> preorder = {1,2,3,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    KthLevel(root, 3);

    return 0;
}