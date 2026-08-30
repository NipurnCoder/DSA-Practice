#include<iostream>
using namespace std;

//Revision Day 107 [30/08/2026]

/*
    LeetCode 230: Kth Smallest Element in a BST
             530: Minimun Absolute Differencce in BST

    Approach:
    1. Use Inorder Traversal: Left → Root → Right.
    2. Inorder traversal of a BST gives nodes in sorted order.
    3. Maintain a counter to count visited nodes.
    4. When count + 1 == k, the current node is the kth smallest.
    5. Stop traversal immediately once the answer is found.

    Key Idea:
    BST + Inorder Traversal = Sorted Order
    kth visited node = kth smallest element.

    Time Complexity: O(H + k) approximately
    Space Complexity: O(H), due to recursion stack

    Important:
    The counter must be initialized to 0.
*/

class TreeNode{
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
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {        //COMPLETE 50 QUESTIONS ON LEET CODE

        if(root == NULL){                           //COMPLETE 100 DSA VIDEOS 
            return -1;
        }

        //left
        if(root->left != NULL){
            int leftAns = kthSmallest(root->left, k);
            if(leftAns != -1){
                return leftAns;
            }
        }

        //root
        if(count+1 == k){
            return root->val;
        }

        count++;

        //right
        if(root->right != NULL){
            int rightAns = kthSmallest(root->right, k);
            if(rightAns != -1){
                return rightAns;
            }
        }
        return -1;
    }
};

int main(){

    TreeNode* root =  new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution s;

    cout<<s.kthSmallest(root, 2);

    return 0;
}