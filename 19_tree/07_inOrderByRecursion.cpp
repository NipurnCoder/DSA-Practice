#include<iostream>
#include<vector>
using namespace std;

//Revision Day 104

/*
    LeetCode 107 : Binary Tree Level Order Traversal II
             106 : Construct Binary Tree from Inorder and Postorder Traversal

    Topic: Binary Tree Inorder Traversal

    Inorder Traversal = Left → Root → Right
    Use recursion: traverse left, store root->val, traverse right.
    Base case: if(root == NULL) return;

    Time Complexity: O(n)
    Space Complexity: O(h) due to recursion stack.
*/

class TreeNode {
public:    
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
        return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       inorder(root, ans);
       return ans;
    }
};

int main(){

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;

    vector<int> ans = s.inorderTraversal(root);

    for(int val : ans){
        cout<<val<<" ";
    }
    return 0;
}