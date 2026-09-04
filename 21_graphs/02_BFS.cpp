#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

//Revision 112

/* 
    LeetCode 1091 : Shortest Path in Binary Matrix

    Topic: Breadth First Search (BFS) for Graph Traversal

    Key Points:
    1. BFS traverses a graph level by level.
    2. BFS uses a Queue data structure.
    3. Use a visited array to avoid visiting a vertex multiple times.
    4. Start from a source vertex and push it into the queue.
    5. Visit all unvisited neighbors and add them to the queue.
    6. For an undirected graph, add both u -> v and v -> u.

    Time Complexity: O(V + E)
    Space Complexity: O(V)

    Remember:
    BFS -> Queue + Visited Array
    DFS -> Recursion/Stack + Visited Array
    Undirected Graph -> add both directions.
    Directed Graph   -> add only u -> v.
*/

class Graph {

    int V;  //V = Vertex
    list<int> *l;

public :
    Graph(int V){    //constructor
        this-> V = V;
        l = new list<int> [V];  //dynamic memory allocation
    }

    void addEdge(int u, int v){ // TC : O(V+E)
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //Breadth First Search
    void bfs(){
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);      //0 = src:source
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