#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

//Revision Day 101

/*
    LeetCode 987 : Vertical Order Traversal of a Binary Tree [Hard]

    Topic: Top View of a Binary Tree

    Approach:
    1. Use BFS (Level Order Traversal) with a queue.
    2. Store each node along with its Horizontal Distance (HD).
    3. Use a map<HD, node value> to store the first node seen at each HD.
    4. BFS ensures the first node at each HD is the topmost node.
    5. Finally, traverse the map to print the top view from left to right.

    Key Concept:
    - Left child  -> HD - 1
    - Right child -> HD + 1
    - Store only the first node for each HD.

    Complexity:
    Time: O(N log N)
    Space: O(N)

    Important:
    Top View = First visible node at every Horizontal Distance.
*/

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

//Top View of a Binary Tree
void topView(Node* root){

    queue<pair<Node*, int>> q; //{node, Horizontal distance}

    map<int, int> m; //<HD, node val>

    if(root == NULL) return;

    q.push({root, 0});

    while(q.size() > 0){

        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }

        if(curr->left != NULL){
            q.push({curr->left, currHD-1});
        }
        if(curr->right != NULL){
            q.push({curr->right, currHD+1});
        }
    }
    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main() {

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    
    topView(root);
    
    return 0;
}