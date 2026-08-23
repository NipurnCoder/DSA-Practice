#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Revision Day 100 [23/08/2026]

/*
    LeetCode 104 : Maximum Depth of Binary Tree
             222 : Count Complete Tree Node
             938 : Range Sum of BST
             226 : Invert Binary Tree

    Topic: Binary Tree - Basic Properties

    Implemented:
    1. buildTree()  -> Builds a binary tree from preorder traversal where -1 represents NULL.
    2. height()     -> Finds the height of the binary tree.
    3. count()      -> Counts the total number of nodes.
    4. sum()        -> Calculates the sum of all node values.

    Key Concepts:
    - Binary Tree is recursively divided into left and right subtrees.
    - Base Case: root == NULL
    - Height = max(leftHeight, rightHeight) + 1
    - Count = leftCount + rightCount + 1
    - Sum = leftSum + rightSum + root->data

    Time Complexity:
    O(n) for height, count and sum.

    Space Complexity:
    O(h) due to recursion stack,
    where h = height of the tree.

    Key Takeaway:
    Most Binary Tree problems can be solved using the same recursive pattern:
    1. Base Case
    2. Solve Left Subtree
    3. Solve Right Subtree
    4. Combine the results.
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

//To Find Height
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt)+1;
}

//TO Find Count of Nodes
int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);
    
    return leftCount + rightCount + 1;
}

//To Find Sum of Nodes
int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

int main(){

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    
    cout<<"Height : "<<height(root)<<endl;
    cout<<"Count : "<<count(root)<<endl;
    cout<<"sum : "<<sum(root)<<endl;

    return 0;
}