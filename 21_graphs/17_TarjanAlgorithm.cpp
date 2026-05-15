#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
                    
class Solution {         //LeetCode : 1192 Hard
public:                  //Bridge Condition

    int time;
    vector<int> dt, low;

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