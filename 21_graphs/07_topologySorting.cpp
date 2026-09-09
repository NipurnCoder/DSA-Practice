#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

//Revision Day 117

/*
    LeetCode 802 : Find Eventual Safe States

    Topic: Topological Sorting using DFS

    Approach:
    1. Create a directed graph using an adjacency list.
    2. Run DFS from every unvisited vertex.
    3. During DFS, visit all neighbouring nodes first.
    4. After all neighbours are processed, push the current node
       into a stack.
    5. Finally, pop the stack to get the topological ordering.

    Why stack?
    A node is pushed only after all its dependencies are processed.
    Therefore, popping the stack gives the required ordering.

    Example:
    Edge: u -> v
    Topological order must contain u before v.

    Time Complexity:
    O(V + E)

    Space Complexity:
    O(V + E)
    - Adjacency list: O(V + E)
    - Visited array: O(V)
    - Stack: O(V)
    - Recursion stack: O(V)

    Important Note:
    Topological sorting is possible only for a DAG
    (Directed Acyclic Graph).

    Key Point:
    DFS Topological Sort = DFS + Stack
    Push node AFTER visiting all neighbours.
*/

class Graph {
    int V;
    list<int> *l;
public :
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdg(int u, int v){
        l[u].push_back(v);  //directed u----->v
    }

    void dfs(int curr, vector<bool> &vis, stack<int> &s){
        vis[curr] = true;

        for(int v : l[curr]){   //l[curr] = neigh
            if(!vis[v]){
                dfs(v, vis, s);

            }
        }
        s.push(curr);
    }

    //Topological Sorting Using DFS
    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }

        while(s.size() > 0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

};    

int main(){
    Graph g(6);

    g.addEdg(3,1);
    g.addEdg(2,3);
    g.addEdg(4,0);
    g.addEdg(4,1);
    g.addEdg(5,0);
    g.addEdg(5,3);
    
    g.topoSort();

    return 0;
}