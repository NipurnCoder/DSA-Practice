#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

//Revision Day 125 [13/11/2026]

/*
    Topic: Minimum Spanning Tree (MST)
    Algorithm: Prim's Algorithm
    LeetCode: 1584 - Min Cost to Connect All Points

    Approach:
    1. Start from node 0 with cost 0.
    2. Use a Min Heap to select the minimum-weight edge.
    3. Extract {weight, node} from the priority queue.
    4. If the node is already visited, skip it.
    5. Otherwise, mark it visited and add its weight to MST cost.
    6. Calculate distances to all unvisited nodes.
    7. Push these candidate edges into the Min Heap.
    8. Repeat until all nodes are visited.

    Manhattan Distance:
    |x1 - x2| + |y1 - y2|

    Data Structures:
    - Priority Queue (Min Heap)
    - Vector<bool> (Visited Array)

    Time Complexity: O(V^2 log V)
    Space Complexity: O(V^2)

    Key Points:
    - Prim's Algorithm is a Greedy Algorithm.
    - MST connects all vertices without cycles.
    - Min Heap selects the minimum-weight candidate.
    - Skip already visited nodes to avoid duplicate processing.
*/

class Solution {    //LeetCode : 1584
public:
    typedef pair<int, int> P;
    using Vec = vector<vector<int>>;     //also use this way

    int manDist(Vec& points, int p1, int p2){
        return (abs(points[p1][0] - points[p2][0]) +
                abs(points[p1][1] - points[p2][1]));
    }

    int minCostConnectPoints(Vec& points) { //Prim's Algorithm
        int n = points.size();

        //Priority Queue - minheap
        priority_queue <P, vector<P>, greater<P>> pq;
        
        // priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        vector<bool> mstSet(n, false);
        int mstCost = 0;

        pq.push({0, 0});    //{wt, node}

        while(pq.size() > 0){

            auto p = pq.top();
            int wt = p.first;
            int node = p.second;

            pq.pop();

            if(mstSet[node]) continue;

            mstSet[node] = true;
            mstCost += wt;

            for(int i=0; i<n; i++){
                if(!mstSet[i]){
                    int edgeWt = manDist(points, node, i);
                    pq.push({edgeWt, i});
                }
            }
        }
        return mstCost;
    }
};

int main() {

    Solution obj;
    using Vec = vector<vector<int>>;
    
    Vec points = {
        {0,0},
        {2,2},
        {3,10},
        {5,2},
        {7,0}
    };

    cout << obj.minCostConnectPoints(points);

    return 0;
}