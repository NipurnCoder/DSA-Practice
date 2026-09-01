#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//Revision Day 109

/*
    LeetCode 1373 : Maximum Sum BST in Binary Tree [Hard]

    Topic: Largest BST in a Binary Tree

    Approach:
        1. Use Postorder Traversal: Left → Right → Root.
        2. For every subtree, maintain 3 pieces of information:
        - min  → minimum value in the subtree
        - max  → maximum value in the subtree
        - sz   → size of the largest BST
        3. A subtree is a BST if:
            root->data > left.max
            AND
            root->data < right.min
        4. If it is a BST:
        - currMin = min(root->data, left.min)
        - currMax = max(root->data, right.max)
        - currSize = left.sz + right.sz + 1
        5. If it is NOT a BST:
        - Keep the larger BST from left or right subtree.

    Base case:
        Empty subtree → {INT_MAX, INT_MIN, 0}

    Key Idea:
        Return information from children so the parent can decide
        whether its entire subtree is a BST.

    Time Complexity: O(n)
    Space Complexity: O(h)
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

//Largst BST in BT
class Info{
public :
    int min, max, sz;

    Info(int mi, int ma, int size){
        min = mi;   //like above class node
        max = ma;
        sz = size;
    }
};

Info helper(Node* root){
    if(root == NULL){
        return Info(INT_MAX, INT_MIN, 0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min){
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.sz + right.sz + 1;

        return Info(currMin, currMax, currSz);
    }

    return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
}

int largestBSTinBT(Node* root){
    Info info = helper(root);
    return info.sz; // maximun BST size
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    
    cout<<largestBSTinBT(root)<<endl;

    return 0;    
}