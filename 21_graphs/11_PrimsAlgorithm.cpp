#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Revision Day 121

/*
    LeetCode 1584 : Min Cost to Connect All Points

    Topic: Prim's Algorithm - Minimum Spanning Tree (MST)

    Problem:
    Find the minimum cost required to connect all vertices
    of a connected, undirected, weighted graph.

    Approach:
    - Start from any vertex (here vertex 0).
    - Use a Min Heap storing {weight, vertex}.
    - Always select the minimum-weight edge.
    - If the vertex is not already in MST:
        1. Mark it as visited/inMST.
        2. Add its edge weight to mstCost.
        3. Push all its unvisited neighbours into the heap.
    - Continue until all vertices are included.

    Important:
    - priority_queue is a Max Heap by default.
    - greater<pair<int,int>> converts it into a Min Heap.
    - Heap stores {weight, vertex}.
    - inMST[] prevents adding the same vertex multiple times.
    - For an undirected edge u-v, add:
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});

    Key Point:
    Prim's Algorithm grows ONE MST starting from a vertex
    by repeatedly choosing the cheapest edge connecting
    the current MST to an unvisited vertex.

    Time Complexity : O(E log V)
    Space Complexity: O(V + E)

*/

int primsMST(int V, vector<vector<pair<int, int>>> adj){

    vector<bool> inMST(V, false);

    //min heap -> {weight, vertex}
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    int mstCost = 0;
    pq.push({0, 0});    //{wt, vertex}
     
    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;
        pq.pop();

    // If vertex is already included, skip it
        if(!inMST[u]){
            inMST[u] = true;
            mstCost += wt;

        // Check all neighbours    
            for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
    
                if(!inMST[v])   //check neigh in MST 
                    pq.push({w, v});
            }
        }
    }
    return mstCost;
}

int main(){
    int V = 4;
    vector<vector<pair<int,int>>> adj(V);

    //undirected weighted graph
    adj[0].push_back({1,10}); //v, wt
    adj[1].push_back({0,10}); //u,wt

    // 0 -- 3 (30)
    adj[0].push_back({3,30});
    adj[3].push_back({0,30});

    adj[0].push_back({2,15});
    adj[2].push_back({0,15});

    adj[1].push_back({3,40});
    adj[3].push_back({1,40});

    adj[2].push_back({3,50});
    adj[3].push_back({2,50});

    cout<<"Cost of MST = "<<primsMST(V, adj)<<endl;

    return 0;

    //Result 55
}