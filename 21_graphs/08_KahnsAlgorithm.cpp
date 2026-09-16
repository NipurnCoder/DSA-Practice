#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

//Revision Day 118 [16/09/2026]
/*
    LeetCode 2115 : Find All Possible Recipes from Given Supplies

    Topic: Topological Sort

    Algorithm: Kahn's Algorithm (BFS)

    Defination:
    Kahn’s Algorithm is a BFS-based algorithm used to perform Topological Sort 
        by repeatedly selecting vertices with indegree 0 and removing their outgoing edges.

    Approach:
    1. Calculate indegree of every vertex.
    2. Put all 0-indegree vertices into a queue.
    3. Pop a vertex and add it to the result.
    4. Decrease indegree of its neighbors.
    5. If any neighbor becomes 0, push it into the queue.
    6. If result size != V, graph contains a cycle.

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)

    Key Point:
    Topological Sort is possible only for a Directed Acyclic Graph (DAG).

    Important:
    A topological ordering is not necessarily unique.
*/

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