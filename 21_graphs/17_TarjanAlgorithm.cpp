#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Revision Day 127 [16/11/2026]

/*
    Topic: Bridges in an Undirected Graph
    LeetCode 1192: Critical Connections in a Network (Hard)
    Link: https://leetcode.com/problems/critical-connections-in-a-network/

    Approach: Tarjan's Algorithm (DFS)

    Key Concepts:
    1. dt[u]  = Discovery time of node u.
    2. low[u] = Earliest discovery time reachable from u
                using DFS tree edges and at most one back edge.
    3. Use DFS to visit all connected components.
    4. Update low[u] using low[v] after DFS returns.
    5. For an already visited neighbour (excluding parent),
    update low[u] using dt[v].

    Bridge Condition:
    if(low[v] > dt[u])
        Edge (u, v) is a Bridge.

    Important:
    Bridge     -> low[v] > dt[u]
    Articulation Point -> low[v] >= dt[u] (root is special)

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
    DFS Auxiliary Space: O(V)

    Revision Note:
    If a child cannot reach its parent or any ancestor
    through a back edge, removing the connecting edge
    disconnects the graph. Hence, it is a Bridge.
*/    

class Solution {         //LeetCode : 1192 Hard
public:                  //Bridge Condition

    int time;
    vector<int> dt, low; //Discovery time, Lowest discovery time

    void dfs(int u, int parU, vector<vector<int>>& adj, vector<vector<int>>& cc){
        dt[u] = low[u] = ++time;

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];

            if(dt[v] == -1){    //!vis
                dfs(v, u, adj, cc);

                //update low
                low[u] = min(low[v], low[u]);

                //Bridge
                if(low[v] > dt[u]){
                    cc.push_back({u,v});
                }
            }
            else if(v != parU){
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //adj
        vector<vector<int>> adj(n);

        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.resize(n, -1);
        low.resize(n);

        vector<vector<int>> bridge;

        for(int i=0; i<n; i++){
            if(dt[i] == -1){ 
                dfs(i, -1, adj, bridge);
            }
        }
        return bridge;
    }
};

int main(){

    int n = 4;

    vector<vector<int>> connections = {
        {0,1},
        {1,2},
        {2,0},
        {1,3}
    };

    Solution obj;

    vector<vector<int>> ans =
        obj.criticalConnections(n, connections);

    cout << "Bridges are:\n";

    for(auto edge : ans) {
        cout << edge[0] << " " << edge[1] << endl;
    }

    return 0;

}