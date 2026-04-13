#include <iostream>
#include <vector>
using namespace std;

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