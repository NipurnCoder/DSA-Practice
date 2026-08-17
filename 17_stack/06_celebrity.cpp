#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Revision Day 94

/*
    LeetCode 977 : Find the Town Judge

    Topic: Celebrity Problem:

    A celebrity is a person who:
    1. Doesn't know anyone → their entire row should be 0.
    2. Everyone knows them → their entire column should be 1 except the diagonal.

    Approach:
    - Push all people into a stack.
    - Compare two people at a time.
    - If i knows j, i cannot be the celebrity → remove i.
    - If i doesn't know j, j cannot be the celebrity → remove j.
    - The remaining person is a potential celebrity.
    - Verify the candidate by checking:
        → Everyone knows the candidate.
        → Candidate knows nobody.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Key Concept:
    Elimination + Verification
*/

int celebrity(vector<vector<int>> arr){  // O(n) = TC, SC

    stack<int> s;

    int n = arr.size();

    for(int i=0; i<n; i++){
        s.push(i);
    }

    while(s.size() > 1){
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(arr[i][j] == 0){
            s.push(i);
        }
        else{
            s.push(j);
        }
    }
 
    int celeb = s.top();

    for(int i=0; i<n; i++){
        if((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
            return -1;
        }
    }
    return celeb;
}

int main(){

    vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};
    int ans = celebrity(arr);
    
    cout<<"Celebrity is : "<<ans<<endl;
    return 0;
}