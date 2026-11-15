#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;      

//Revision Day 126 [14/11/2026]
/*
    LeetCode 787 : Cheapest Flights Within K Stops

    Topic: Graph | BFS | Bellman-Ford | Shortest Path

    Approach:
        1. Build a directed weighted adjacency list.
        2. Use a Queue to traverse nodes while tracking:
        - Current node
        - Total cost
        - Number of stops
        3. Relax edges only when the cost improves and the stop
        constraint is satisfied.
        4. Return -1 if the destination is unreachable.

    Important Points:
        - At most K stops means at most K+1 flights (edges).
        - A simple dist[] array with queue-based relaxation is
            not guaranteed to work for all test cases.
        - Track cost separately for different stop counts.
        - Bellman-Ford is a reliable alternative for this problem.
        - Use a temporary distance array in Bellman-Ford so that
            each iteration adds at most one edge.

    Complexity (Bellman-Ford):
    Time: O(K * E)
    Space: O(V)

    Key Learning:
        Unlike ordinary Dijkstra, the cheapest path also depends
        on the number of stops, not just the total cost.
*/

class Solution {         
public:            

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        //Build Graph
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        //Simple Queue
        queue<pair<int, pair<int, int>> > q; //(node,{u, wt})
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        q.push({src, {0, -1}});

        while(q.size() > 0){
            auto val = q.front();
            int u = val.first;
            int cost = val.second.first;
            int stops = val.second.second;
            q.pop();

            for(auto edge : graph[u]){
                int v = edge.first;
                int wt = edge.second;

                if(dist[v] > cost + wt && stops+1 <= k){
                    dist[v] = cost + wt;

                    q.push({v,{dist[v], stops+1}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};

int main(){
    Solution s;

    int n = 4;

    vector<vector<int>> flights = {{0, 1, 100}, {1,2,100}, {2,3,100}, {0,3,500}};

    int src = 0;
    int dst = 3;
    int k = 1;

    cout<<s.findCheapestPrice(n, flights, src, dst, k);

    return 0;
}