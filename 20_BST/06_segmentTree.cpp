#include<iostream>
#include<vector>
using namespace std;

//[16/10/2026]
//LeetCode 2916 : Subarrays Distinct Element Sum of Squares II [Hard]

class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int n;

    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;    //Lazy Propogation

    void lazyAddition(int i, int l, int r, int val){

        int len = (r-l+1); //no. of Nodes child

        sqSumSegTree[i] += 2*val*sumSegTree[i] + len * val * val;
        sumSegTree[i] += (len * val);
    }

    void updateRange(int st, int end, int i, int l, int r, int val){

        //Update Lazy Tree Val
        if(lazyTree[i] != 0){
            lazyAddition(i, l, r, lazyTree[i]);

            //Check leaf Node
            if(l != r){ 
                lazyTree[2*i+1] += lazyTree[i]; //left
                lazyTree[2*i+2] += lazyTree[i]; //right
            }
            lazyTree[i] = 0;
        }

    //Build Segment Tree

        //Out of Range
        if(l > end || r < st || l > r)
            return;

        //Completely within range
        if(l >= st && r <= end){
            lazyAddition(i, l, r, val);

            if(l != r){
                lazyTree[2*i+1] += val; //left
                lazyTree[2*i+2] += val; //right
            }
            return;
        }
        
        //Overlapping range
        int mid = l + (r-l)/2;

        updateRange(st, end, 2*i+1, l, mid, val); //left chid
        updateRange(st, end, 2*i+2, mid+1, r, val); //right child

        sumSegTree[i] = sumSegTree[2*i+1] + sumSegTree[2*i+2]; //root = left + right
        sqSumSegTree[i] = sqSumSegTree[2*i+1] + sqSumSegTree[2*i+2]; //root = l + r

    }

    int sumCounts(vector<int>& nums) {

       n = nums.size();

       //Initialization
       sqSumSegTree.assign(4*n, 0); //[2n+1] is no. of nodes, where n is no. of child nodes
       sumSegTree.assign(4*n, 0);   //(4*n) is to make pow(2)
       lazyTree.assign(4*n, 0);     // GP: (a/r-1)

       vector<int> lastSeenIdx(100001, -1); //Segment Tree in vector form
       ll result = 0;

        for(int i=0; i<n; i++){ //Traverse each node

            int st = lastSeenIdx[nums[i]] + 1; //visite (-1 + 1 = 0)
            int end = i;

            updateRange(st, end, 0, 0, n-1, 1);

            result = (result + sqSumSegTree[0]) % MOD;

            lastSeenIdx[nums[i]] = i;
        }

        return result;
    }
};