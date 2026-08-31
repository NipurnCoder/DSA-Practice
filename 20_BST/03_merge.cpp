#include<iostream>
#include<vector>
using namespace std;

//Revision Day 108

/*
    LeetCode 1382 : Balance a Binary Search Tree
             1305 : All Elements in Two Binary Search Trees
             
    Topic: Merge Two Binary Search Trees

    Approach: 
    1. Perform Inorder Traversal on both BSTs.
    2. Inorder traversal of a BST gives elements in sorted order.
    3. Store the inorder elements of both BSTs in separate arrays.
    4. Merge both sorted arrays using the Two Pointer Technique.
    5. The merged array contains all elements in sorted order.
    6. Build a balanced BST from the merged sorted array by choosing
       the middle element as the root.
 
    Key Idea: 
    BST + Inorder Traversal = Sorted Array
    Two Sorted Arrays + Two Pointers = Merged Sorted Array
    Sorted Array + Middle Element = Balanced BST
 
    Time Complexity: O(n + m)
    Space Complexity: O(n + m)
 
    Important:
    1. Inorder traversal is used because BST gives sorted order.
    2. Two pointers efficiently merge the two sorted arrays.
    3. Using the middle element while building the BST keeps it balanced.
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
 
//inorder : left, root, right
void inorder(Node* root, vector<int>& arr){
    if(root == NULL){
        return ;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* buildBSTFromSorted(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, st, mid-1);
    root->right = buildBSTFromSorted(arr, mid+1, end);

    return root;
}

Node* merge2BST(Node* root1, Node* root2){
    vector<int> arr1, arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> temp;   //final BST inorder : sorted

    int i=0, j=0;
    
    while(i < arr1.size() && j < arr2.size()) {

        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        } else {
            temp.push_back(arr2[j++]);
        }
    } 

    while(i<arr1.size()){
        temp.push_back(arr1[i++]);
    }

    while(j < arr2.size()){
        temp.push_back(arr2[j++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size()-1);  //sorted array, st, end
}

int main() {
    vector<int> arr1 = {8,2,1,10};
    vector<int> arr2 = {5,3,0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = merge2BST(root1, root2);
    vector<int> seq;
    inorder(root, seq);

    for(int v : seq){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}