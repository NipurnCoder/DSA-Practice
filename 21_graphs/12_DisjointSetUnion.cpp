#include<iostream>
#include<vector>
using namespace std;

//Revision Day 122 [19/10/2026]

/*
    Topic: DSU / Union-Find
    Approach: Union by Rank + Path Compression

    Key Points:
    1. DSU maintains disjoint (non-overlapping) sets.
    2. par[i] = i means i is the root/representative of its set.
    3. find(x) returns the representative of x's set.
    4. Path Compression:
        par[x] = find(par[x]);
        Makes visited nodes point directly to the root.
    5. Union by Rank:
        - Find roots of both nodes first.
        - If roots are equal, they already belong to the same set.
        - If ranks are equal, attach one root to the other and
            increment the surviving root's rank.
        - Otherwise, attach the lower-rank root to the higher-rank root.
    6. Rank increases only when both root ranks are equal.
    7. Path compression changes parent pointers, not ranks.

    Time Complexity:
    - Constructor: O(n)
    - find(): O(α(n)) amortized
    - unionByRank(): O(α(n)) amortized
    - getInfo(): O(n)

    Space Complexity: O(n)

    Important Notes:
    - Always perform union using the roots returned by find().
    - If find(a) == find(b), both nodes belong to the same set.
    - Use `if (parA == parB) return;` in unionByRank()
        to avoid unnecessary rank updates.
    - α(n) is the inverse Ackermann function, practically
        constant for realistic input sizes.

*/

class DisjointSetUnion {
public :
    int n;
    vector<int> par, rank;   

    DisjointSetUnion(int n){
        this->n = n;

        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){   //case 1
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){   //case 2
            par[parB] = parA;
        }
        else{   //case 3
            par[parA] = parB;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }

        //return find(par[x]);    
        
        return par[x] = find(par[x]);   //path compression
    }
    
    void getInfo() {
        for(int i=0; i<n; i++){
            cout<<par[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<n; i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    DisjointSetUnion dsu(6);

    dsu.unionByRank(0,2);
    cout<<dsu.find(2)<<endl;

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);
    cout<<dsu.find(2)<<endl;

    dsu.unionByRank(0,4);

    dsu.getInfo();

    return 0;
}