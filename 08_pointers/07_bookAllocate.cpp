#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//Revision Day 25 

/*
    Book Allocation Problem

    Approach - Binary Search on Answer

    1. The minimum answer can be the largest book.
    2. The maximum answer can be the sum of all books.
    3. Use binary search on this range.
    4. For each mid, check if all books can be allocated
       to at most m students such that no student gets
       more than mid pages.

    Time  - O(n * log(sum))
    Space - O(1)
*/

bool isvalid(vector<int> &arr, int n, int m, int maxAllowedPgs)
{
    //O(n)
    int student = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPgs)
        {
            return false;
        }
        if (pages + arr[i] <= maxAllowedPgs)
        {
            pages += arr[i];
        }
        else
        {
            student++;
            pages = arr[i];
        }
    }
    //return student > m ? false : true;
    return student <= m;
}

int bookAllocate(vector<int> &arr, int n, int m)
{

    //m = no of student, n = no of books
    if (m > n)
    {
        return -1;
    }

    //Calculate Sum
    //O(n)
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int ans = -1;
    //int st = *max_element(arr.begin(), arr.end());
    int st = 0; 
    int end = sum;

    //O(log range)
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isvalid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 1, 3, 4};
    int m = 2, n = 4;

    int ans = bookAllocate(arr, n, m);
    cout<<"the answer is "<<ans<<endl;

    //cout << bookAllocate(arr, n, m) << endl;
    return 0;
}
