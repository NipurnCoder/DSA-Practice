#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

//Revision Day 115 [7/9/2026]

/*
    LeetCode 785 : Is Graph Bipartite?

    Topic: Cycle Detection in Undirected Graph using BFS

    Key Points:
    1. Use BFS with a queue storing {node, parent}.
    2. Mark a node visited when pushing it into the queue.
    3. If a neighbor is unvisited, push it with the current node as parent.
    4. If a neighbor is already visited and is NOT the parent,
        then a cycle exists.
    5. For disconnected graphs, run BFS from every unvisited vertex.

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
*/


class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V){
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleUndirBFS(int src, vector<bool> &vis){
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = true;

        while(q.size() > 0){
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            list<int> neigh = l[u];
            for(int v :  neigh){
                if(!vis[v]){
                    q.push({v, u});
                    vis[v] = true;
                } else if(v != parU){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++){ //for other disconnected src 
            if(!vis[i]){
                if(isCycleUndirBFS(i, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(1,2);

    cout<<g.isCycle()<<endl;

    return 0;
}
