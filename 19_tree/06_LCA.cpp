#include<iostream>
#include<vector>
using namespace std;

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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        Node* leftLCA = lowestCommonAncestor(root->left, p, q);
        Node* rightLCA = lowestCommonAncestor(root->right, p ,q);

        if(leftLCA && rightLCA){
            return root;
        }else if(leftLCA != NULL){
            return leftLCA;
        }else{
            return rightLCA;
        }
    }

    int main(){
        vector<int> preorder = {3,5,1,6,2,0,8,-1,-1,7,4,};
        Node* buildTree(preorder);

        lowestCommonAncestor(root, 5, 1);

        return 0;
    }