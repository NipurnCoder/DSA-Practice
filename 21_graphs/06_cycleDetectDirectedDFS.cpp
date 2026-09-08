#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

//Revision Day 116

/*
    LeetCode 802 : Find Eventual Safe States

    Topic: Cycle Detection in a Directed Graph

    Approach:
    1. Use DFS to traverse the directed graph.
    2. Use visited[] to track nodes that have already been visited.
    3. Use recPath[] to track nodes in the current DFS recursion path.
    4. If we encounter a node that is already in recPath[], a cycle exists.
    5. Reset recPath[curr] = false while backtracking.
    6. Check every unvisited node to handle disconnected components.

    Key Concept:
    - visited[] = Node has been visited before.
    - recPath[] = Node is currently in the DFS path.
    - visited[v] && recPath[v] → Cycle detected.

    Complexity:
    Time: O(V + E)
    Space: O(V)

    Important:
    Directed Graph Cycle = Back Edge to a node in the current recursion path.
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
        l[u].push_back(v); //directed u--->v
    }

    //Cycle Detection
    bool isCycleDirDFS(int curr, vector<bool> &vis, vector<bool> &recPath){
        vis[curr] = true;
        recPath[curr] = true;

        for(int v : l[curr]){
            if(!vis[v]){
                if(isCycleDirDFS(v, vis, recPath)){
                    return true;
                }
            } else if(recPath[v]){
                return true;
            }
        }
        recPath[curr] = false;
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i =0; i<V; i++){
            if(!vis[i]){
                if(isCycleDirDFS(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(4);

    g.addEdg(1,0);
    g.addEdg(0,2);
    g.addEdg(2,3);
    g.addEdg(3,0);
    
    cout<<g.isCycle()<<endl;

    return 0;
}