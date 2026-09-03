#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Revision Day 111 [3/09/2026]

/*
    LeetCode 1971 : Find if Path Exists in Graph

    Topic: Graph Representation using Adjacency List

    Key Points:
    1. Graph consists of vertices (V) and edges (E).
    2. Adjacency List stores all neighbors of each vertex.
    3. Used array of linked lists: list<int> *l.
    4. For an undirected graph, add both u -> v and v -> u.


    Time Complexity: O(1) addEdge()
    Space Complexity: O(V + E) Traversing / Printing

    Remember:
    Undirected Graph -> add both directions.
    Directed Graph   -> add only u -> v.
*/

class Graph {
    int V;
    list<int> *l; // Adjacency list

public :
    Graph(int V){
        this->V = V;
        l = new list<int> [V]; // V = vertex
    }

    void addEdge(int u, int v){ // u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<<i<<" : ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    cout<<"Adjacency List : "<<endl;
    g.printAdjList();

    return 0;
}

