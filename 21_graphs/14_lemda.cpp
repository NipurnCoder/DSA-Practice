#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Revision Day 124 [08/11/2026]

/*
    LeetCode 1665: Minimum Initial Energy to Finish Tasks
    
    Topic: Greedy Algorithm + Custom Sorting + Lambda Function

    Approach:
        1. Sort tasks in decreasing order of (minimum - actual).
        2. If current energy is less than minimum energy,
            add the required difference to initial energy.
        3. Subtract actual energy after completing each task.
        4. Return the minimum initial energy required.

    Lambda Function:
        [](const vector<int>& a, const vector<int>& b)
        - [] : Capture clause, captures no outside variables.
        - (a, b) : Parameters representing two tasks.
        - const vector<int>& : Passes vectors by reference
        without copying and prevents modification.
        - a[1] - a[0] : Energy difference of task a.
        - b[1] - b[0] : Energy difference of task b.
        - > : Sorts tasks in descending order of energy difference.
        - return : Returns true if task a should come before task b.

    Time Complexity: O(n log n)
    Space Complexity: O(log n) - Sorting stack space

    Key Points:
        - actual = Energy required to complete the task.
        - minimum = Minimum energy required before starting.
        - energy = Current energy available.
        - ans = Minimum initial energy required.

    Important Note:
        Greedy sorting helps minimize the initial energy required.
*/

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