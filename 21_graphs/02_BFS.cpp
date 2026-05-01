#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int V;      //V = Vertex
    list<int> *l;
public :
    Graph(int V){   //constructor
        this-> V = V;
        l = new list<int> [V]; //dynamic memory allocation
    }

    void addEdge(int u, int v){ // TC : O(V+E)
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //Breadth First Search
    void bfs(){
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);   //0 = src:source
        vis[0] = true;  //Create src

        while(q.size() > 0){
            int u = q.front();  //u-v
            q.pop();

            cout<<u<<" ";

            for(int v : l[u]){  //v-> immediate neighbour
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout<<"Breadth First Search : ";
    g.bfs();

    return 0;
}