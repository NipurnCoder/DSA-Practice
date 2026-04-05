#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

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
