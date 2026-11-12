#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

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