#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

//Revision Day 120 [03/10/2026]

/*
    LeetCode 787 : Cheapest Flights Within K Stops

    Topic: Bellman-Ford Algorithm

    Approach:
    - Initialize dist[src] = 0 and all other distances as INT_MAX.
    - Relax every edge V-1 times.
    - For edge u -> v:
        if(dist[u] != INT_MAX && dist[v] > dist[u] + wt)
            update dist[v].
    - V-1 iterations are enough because the shortest simple path
      can contain at most V-1 edges.

    Time Complexity: O(V * E)
    Space Complexity: O(V)

    Key Points:
    - Works with negative edge weights.
    - Unlike Dijkstra, Bellman-Ford can handle negative weights.
    - Can detect negative weight cycles using one extra relaxation pass.
    - Always check dist[u] != INT_MAX before adding weight to avoid overflow.

    Important:
    Bellman-Ford = Relax all edges V-1 times.
*/

class Edge {
public :
    int v;
    int wt;

    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src, vector<vector<Edge>> g, int V){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){ //u---->v
            for(Edge e : g[u]){
                //Edge Relaxation
                if(dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }
    for(int i=0; i<V; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int V = 5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2)); //{neigh, wt}
    g[0].push_back(Edge(2,4)); // 0 -> 2, weight 4

    g[1].push_back(Edge(4,-1)); // 1 -> 4, weight -1
    g[1].push_back(Edge(2,-4)); // 1 -> 2, weight -4

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    bellmanFord(0, g, V);

    return 0;

    //Output: Shortest Dist = 0 2 -2 0 1;

}