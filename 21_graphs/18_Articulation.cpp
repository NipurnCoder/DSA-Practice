#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

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
                low[u] = min(low[u], low[v]);
            }
        }
        if(parU == -1 && children > 1){
            cp.insert(u);
        }
    }

    int articulationPoints(){

        int time = 0;
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