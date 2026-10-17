#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
    Revision : 17/10/2026
    Topic: OOP + 3Sum Problem
    Approach: Brute Force + Set (Duplicate Removal)

    Key Points:
    1. ThreeSum class stores the array using a private data member.
    2. Constructor initializes the array using the input vector.
    3. Three nested loops select every possible triplet (i, j, k).
    4. Check whether arr[i] + arr[j] + arr[k] == 0.
    5. Sort each valid triplet to maintain a consistent order.
        Example: {0, -1, 1} becomes {-1, 0, 1}.
    6. Use set<vector<int>> to prevent duplicate triplets.
    7. Store each unique triplet in ans and return the result.
    8. display() prints all the triplets.

    Time Complexity: O(n^3 * log U)
    - O(n^3) triplets are checked.
    - Sorting each triplet takes O(1) time because its size is always 3.
    - Set insertion/search takes O(log U) comparisons, where U is the number
        of unique triplets; each vector comparison takes O(1) time here.
    - Overall: O(n^3 + n^3 log U), commonly simplified to O(n^3 log U).

    Space Complexity: O(U)
    - Stores unique triplets in the set and answer vector.
    - U = number of unique triplets.

    Important Note:
    - This is the brute-force approach.
    - A more efficient approach sorts the array and uses two pointers.
    - Optimized 3Sum complexity: O(n^2) time.
*/

class ThreeSum {
private:
    vector<int> arr;   // data member (stores array)

public:
    // constructor to initialize array
    ThreeSum(vector<int> input) {
        arr = input;
    }

    // member function to find triplets
    vector<vector<int>> findTriplets() {

        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = arr.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){

                    if(arr[i] + arr[j] + arr[k] == 0){
                        vector<int> trip = {arr[i], arr[j], arr[k]};
                        sort(trip.begin(), trip.end());

                        if(s.find(trip) == s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }
        return ans;
    }

    // function to print result
    void display(vector<vector<int>> result) {
        for(auto &trip : result){
            for(int x : trip){
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    vector<int> data = {-1,0,1,2,-1,-4};

    ThreeSum obj(data);                 // object created
    vector<vector<int>> result = obj.findTriplets();

    obj.display(result);

    return 0;
}
