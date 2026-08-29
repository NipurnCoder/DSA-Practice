#include<iostream>
#include<vector>
using namespace std;

//Revision Day 106

/*
    LeetCode 701 : Insert into BST
             450 : Delete Node in BST

    Topic: Binary Search Tree Operations (BST)

    Approach:
        1. Build the BST by inserting each element according to BST property.
        2. Use Inorder Traversal to print elements in sorted order.
        3. Search for a key by comparing it with the current node.
        4. If key < root->data, move to the left subtree.
        5. If key > root->data, move to the right subtree.
        6. For deletion, handle all 3 cases:
            - Node has no child.
            - Node has one child.
            - Node has two children.
        7. For two children, find the Inorder Successor
            (leftmost node in the right subtree).

    Key Concept:
        - Left subtree  -> values smaller than root
        - Right subtree -> values greater than or equal to root
        - Inorder Traversal of BST -> Sorted Order
        - Inorder Successor -> Smallest node in right subtree

    Complexity:
        - Average Search/Insert/Delete: O(log N)
        - Worst Case Search/Insert/Delete: O(N)
        - Inorder Traversal: O(N)
        - Space: O(H), where H is the height of the BST

    Important:
        BST property = Left < Root <= Right.
        Deletion with 2 children is done using the Inorder Successor.

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

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    } else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int val : arr){
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool Search(Node* root , int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true ;
    }

    if(key < root->data){
        return Search(root->left, key);
    } else {
        return Search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root){ //left most node in right subtree
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node*root, int key){  //key is val to delete
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = delNode(root->left, key);
    } else if(key > root->data){
        root->right = delNode(root->right, key);
    }else{
        //key == root

        //Case 1: No left child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        //Case 2: No right child
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //Case 3: Two children
        else{
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data; //overwrite or replace
            root->right = delNode(root->right, IS->data); 

            // Node* temp = root->right;
            // while (temp->left != nullptr)
            //     temp = temp->left;

            // root->data = temp->data;
            // root->right = delNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};

    Node* root = buildBST(arr);
    inorder(root);
    cout<<endl;

    cout<<Search(root, 6)<<endl;

    root = delNode(root, 1);
    inorder(root);
    cout<<endl;

    return 0;
}
