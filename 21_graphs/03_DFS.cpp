#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

//Revision Day 113

/*
    LeetCode 841 : Keys and Rooms

    Topic: Graph - Depth First Search (DFS)

    Key Points:
    1. Graph is represented using an Adjacency List.
    2. DFS explores a node and goes as deep as possible before backtracking.
    3. Recursion is used to implement DFS.
    4. visited[] prevents revisiting nodes and infinite recursion.
    5. For an undirected graph, every edge is stored in both directions.

    6. addEdge() -> O(1)
    7. DFS Traversal -> O(V + E)
    8. Space Complexity -> O(V) for visited array + recursion stack.
    
    DFS Pattern:
    Mark → Visit → Explore unvisited neighbors → Backtrack
*/

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){     //TC : O(V+E)
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //heplper Function to pass values
    void helperDFS(int u, vector<bool> &vis){
        cout<<u<<" ";
        vis[u] = true; //first make Visited then move to another node

        for(int v : l[u]){
            if(!vis[v]){
                helperDFS(v, vis);
            }
        }
    }

    //Deapth First Search
    void dfs(){
        int src = 0;
        vector<bool> vis(V, false);

        helperDFS(src, vis);
        cout<<endl;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout<< "Depth First Search : ";
    g.dfs();

    return 0;
}