#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//Revision Day 128 [18/11/2026]

/*
    LeetCode 1192 : Critical Connections in a Network (Bridges)

    Topic: Articulation Points (Cut Vertices)
    
    Algorithm: Tarjan's Algorithm
    Approach: DFS + Discovery Time + Low Time

    Key Concepts:
    1. dt[u]  = Discovery time of node u.
    2. low[u] = Earliest discovery time reachable from u
                using DFS tree edges and at most one back edge.
    3. Use DFS to visit all connected components.
    4. Update low[u] using low[v] after DFS returns.
    5. For an already visited neighbour (excluding parent),
       update low[u] using dt[v].
    6. Maintain children count to handle the root node.

    Articulation Point Conditions:

    1. Non-root node:
       if(low[v] >= dt[u])
           Node u is an Articulation Point.

    2. Root node:
       if(children > 1)
           Node u is an Articulation Point.

    Important:
    Bridge                  -> low[v] > dt[u]
    Articulation Point      -> low[v] >= dt[u]
    Root Articulation Point -> DFS children > 1

    Time Complexity: O(V + E) for DFS
    Space Complexity: O(V + E)
    DFS Auxiliary Space: O(V)

    Revision Note:
    If a child cannot reach an ancestor of the current node
    through a back edge, removing the current node disconnects
    that child subtree from the remaining graph.

    Special Case:
    The root node is an articulation point only when it has
    more than one independent DFS child.
*/

class Graph {
public : 
    int V;
    vector<vector<int>> adj;

    int time;
    vector<int> dt, low;

    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void Edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parU, set<int>& cp){    //Tarjan's Alogorithm

        dt[u] = low[u] = ++time; //dt = discovery Time
        int children = 0;

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];

            if(dt[v] == -1){
                children++;
                dfs(v, u, cp);

                //update low
                low[u] = min(low[u], low[v]);

                if(parU != -1 && low[v] >= dt[u]){
                    cp.insert(u);   //Articulation Point
                }
            } else if(v != parU){
                low[u] = min(low[u], dt[v]);
            }
        }
        if(parU == -1 && children > 1){
            cp.insert(u);
        }
    }

    int articulationPoints(){

        time = 0;
        dt.resize(V, -1);    //dt = -1 -> unvisited node
        low.resize(V);

        set<int> criticalPoints;

        for(int i=0; i<V; i++){
            if(dt[i] == -1){
                dfs(i, -1, criticalPoints);
            }
        }

        //Print the Critical Points
        for(auto val : criticalPoints){
            cout<<val<<" ";
        }
        cout<<endl;

        return criticalPoints.size();
    }
};

int main(){
    Graph g(6);

    g.Edge(1,0);
    g.Edge(1,2);

    g.Edge(4,3);
    g.Edge(4,5);
    g.Edge(4,1);

    cout<<g.articulationPoints()<<endl;

    return 0;
}