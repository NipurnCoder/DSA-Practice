#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;        //LeetCode : 1345 Hard

class Solution{     
public:
    int minJumps(vector<int>& arr){ //use BFS, unordered map 

        int n = arr.size();

        //contain 1 element only
        if(n == 1) return 0;

        unordered_map<int, vector<int>> m;  //map

        //Store same value in arr 
        for(int i=0; i<n ;i++){
            m[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        int jumps = 0;

        q.push(0);
        vis[0] = false;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){

                int idx = q.front();
                q.pop();

                //Reached at end
                if(idx == n-1){
                    return jumps;
                }

                //Visite same element
                for(int next : m[arr[idx]]){
                    if(!vis[next]){
                        vis[next] = true;
                        q.push(next);
                    }
                }

                //Most imp to clear map for repeating on same val
                m[arr[idx]].clear();

                //Right
                if(idx+1 < n && !vis[idx+1]){
                    vis[idx+1] = true;
                    q.push(idx+1);
                }

                //Left
                if(idx-1 >= 0 && !vis[idx-1]){
                    vis[idx-1] = true;
                    q.push(idx-1);
                }
            }
            jumps++;
        }
        return -1;
    }
};

int main(){
    Solution s;

    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404}; //0-->4-->3-->9

    cout<<s.minJumps(arr)<<endl;

    return 0;
}