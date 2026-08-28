#include <iostream>
#include <vector>
using namespace std;

//Revision Day 105 [28/08/2026]

/*
    LeetCode 700 : Search in a Binary Search Tree

    Topic: Morris Inorder Traversal

    Morris Traversal performs -> Inorder = Left → Root → Right without recursion or a stack.

    Key idea: Find the inorder predecessor and create a temporary **thread** back to the current node.

    * curr->left == NULL → visit curr, move right.
    * Left child exists → find inorder predecessor.
    * IP->right == NULL → create thread and move left.
    * IP->right == curr → remove thread, visit curr, move right.

    Time Complexity: O(n) ⏱
    Extra Space: O(1)

    Remember: Create thread → Go left → Come back → Remove thread → Visit → Go right
*/    

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;

                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    IP->right = curr;   // create thread
                    curr = curr->left;
                } else {
                    IP->right = NULL;   // remove thread
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    /*
        Create Tree:
              1
               \
                2
               /
              3

        Inorder: 1 3 2
    */


    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}