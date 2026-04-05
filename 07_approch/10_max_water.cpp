#include<iostream>
#include<vector>
using namespace std;

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

int optimal_2pointer(vector<int>&height){ //O(n)
    int mw=0;
    int n = height.size();
    int lp=0, rp=n-1;

    while(lp<rp){
        int wd = rp-lp;
        int ht = min(height[lp],height[rp]);
        int cw = wd*ht;
        mw = max(mw, cw);

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