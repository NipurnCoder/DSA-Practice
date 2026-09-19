#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

//Revision Day 119 [19/09/2026]

/*
    LC 743 : Network Delay Time

    Topic: Dijkstra's Algorithm

    Problem: Single Source Shortest Path

    Approach: Adjacency List + Min Heap + Edge Relaxation

    1. Dijkstra finds the shortest distance from one source
        to all other vertices.
    2. Use a Min Heap to always process the vertex with
        the smallest current distance.
    3. Edge Relaxation:
        if(dist[v] > dist[u] + wt)
            dist[v] = dist[u] + wt;
    4. greater<pair<int,int>> makes priority_queue a Min Heap.
    5. Multiple entries of the same vertex can exist in the
        priority queue because a shorter distance may be found later.

    Time Complexity: O((V + E) log V)
    Space Complexity: O(V + E)

    Important Note :
        Dijkstra works only when all edge weights are non-negative.
        It does NOT work correctly with negative edge weights.
*/

class Edge {
public :
    int v;
    int wt;

    Edge(int v, int wt){    //Edge with weight
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>>& g, int V){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    //Priority Queue (Max Heap)
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq; //Min Heap
    pq.push({0, src});

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        for(Edge e : g[u]){     //Edge Relaxation
            if(dist[e.v] > dist[u] + e.wt){     //4 > 2 + 1
                dist[e.v] = dist[u] + e.wt;     //3
                pq.push({dist[e.v], e.v});
            }
        }
    }
    for(int i=0; i<V ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));  //{destination, weight}
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    dijkstra(0, g, V);

    return 0;

}