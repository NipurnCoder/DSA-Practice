#include<iostream>
#include<vector>
#include<queue>
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
    root->left = buildTree(preorder);   //LEFT
    root->right = buildTree(preorder);  //RIGHT

    return root;
}
// pre-order traverse [root, lefft, right]
void preOrderTraverse(Node* root){  //O(n) 
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

// in-order traverse [left, root, right]
void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//post-order traversal [left, right, root]
void postOrder(Node* root){
    if(root == NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//level-order traversal [level wise]
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

//level-order by nextline
void levelOrderByLine(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            } else{
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4,-1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    preOrderTraverse(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    levelOrder(root);
    cout<<endl;

    levelOrderByLine(root);
    
    return 0;
}