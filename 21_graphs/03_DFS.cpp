#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

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
        vis[u] = true;

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