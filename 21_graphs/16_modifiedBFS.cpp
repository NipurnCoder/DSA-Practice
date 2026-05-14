#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;     //LeetCode : 787 

class Solution {         //Dijkstra's Algorithm + BFS approach : some modification like not use of Priority_Queue
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