#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

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