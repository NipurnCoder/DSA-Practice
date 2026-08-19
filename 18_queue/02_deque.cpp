#include<iostream>
#include<deque>
using namespace std;

//Revision Day 96

/*
    LeetCode 1438 : Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

    Topic: Deque (Double Ended Queue)
        A deque allows insertion and deletion from both
        the front and the back.

    Implemented:
    1. push_back()
    2. push_front()
    3. pop_back()
    4. front()
    5. back()

    Example:
        dq = [1, 2, 3]
        push_front(4) → [4, 1, 2, 3]
        pop_back()    → [4, 1, 2]

    Output:
        4 2

    Time Complexity:
        push_front() → O(1)
        push_back()  → O(1)
        pop_front()  → O(1)
        pop_back()   → O(1)
        front()      → O(1)
        back()       → O(1)

    Space Complexity: O(n)

    Key Point:
        Deque = Double Ended Queue
        We can insert and delete from both ends.
*/

int main(){

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4);

    dq.pop_back();

    cout<<dq.front()<<" "<<dq.back()<<endl;

    return 0; 
}