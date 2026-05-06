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
        l = new list<int> [V];  //TC : O(V+E)
    }

    void addEdg(int u, int v){
        l[u].push_back(v);  //directed u----->v
    }

    void topoSort(){
        vector<int> res;
        
        //Indegre of node
        vector<int> indeg(V, 0);

        for(int u=0; u<V; u++){
            for(int v : l[u]){
                indeg[v]++;
            }
        }

        // 0 indegre push in Queue
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        //BFS
        while(q.size() > 0){

            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int v : l[curr]){
                indeg[v]--;

                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        //Result
        for(int val : res){
            cout<<val<<" ";
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
    g.addEdg(5,2);
    
    g.topoSort();

    return 0;
}