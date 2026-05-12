#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {        //LeetCode Hard:1665 
public: 
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
            [](vector<int>& a, vector<int>& b) {    //Lemda Function
                return (a[1] - a[0]) > (b[1] - b[0]);
            });

        int energy = 0;
        int ans = 0;

        for (auto &t : tasks) {

            int actual = t[0];
            int minimum = t[1];

            if (energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            energy -= actual;
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<vector<int>> tasks {{1,2}, {2,4}, {4,8}};

    cout<<s.minimumEffort(tasks);

    return 0;
}