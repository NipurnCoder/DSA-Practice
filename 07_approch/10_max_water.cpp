#include<iostream>
#include<vector>
using namespace std;

//Revision Day 10

/*

 LeetCode-11 : Container With Most Water

 Approach 1 : Brute Force
    - find width, ht, currWater one by one  
    - Takes Time O(n2)

 Approach 2 : Two pointer
    -use two pointer approach to find ht, wd, cw  
    -Takes Time O(n)
*/


//function 1
int max_water(vector<int>& height){ //O(n^2)
    int maxWater=0;
    int n = height.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int width = j-i;
            int ht = min(height[i], height[j]);
            int currWater = width*ht ;

            maxWater = max(maxWater,currWater);
        }
    }
    return maxWater;
}

//function 2
int optimal_2pointer(vector<int>&height){ //O(n)
    int mw=0;
    int n = height.size();
    int lp=0, rp=n-1;
    //lp = left ptr, rp = right ptr

    while(lp<rp){
        int wd = rp-lp;
        int ht = min(height[lp],height[rp]);
        int cw = wd*ht;
        mw = max(mw, cw);

        //ternary condition
        height[lp] < height[rp] ? lp++ : rp--;
    }
    return mw;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = max_water(height);
    cout<<"Max area of water : "<<ans<<endl;

    int optimal_ans = optimal_2pointer(height);
    cout<<"Max area of water by optimal approch : "<<optimal_ans<<endl;

    return 0;
}