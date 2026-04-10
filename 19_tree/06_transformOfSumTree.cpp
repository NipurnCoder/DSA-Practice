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

void preOrder(Node* root){  //O(n) 
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//Transform of Sum Tree
int sumTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftsum = sumTree(root->left);
    int rightsum = sumTree(root->right);

    root->data += leftsum + rightsum;

    return root->data;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout<<"Before conversion : ";
    preOrder(root);
    cout<<endl;

    sumTree(root);

    cout<<"After conversion : ";
    preOrder(root);
    cout<<endl;

    return 0; 
}