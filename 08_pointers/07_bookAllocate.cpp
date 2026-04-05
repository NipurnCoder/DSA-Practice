// #include <iostream>
// #include <vector>
// using namespace std;

// bool isvalid(vector<int> &arr, int n, int m, int maxAllowedPgs)
// {
//     int student = 1, pages = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > maxAllowedPgs)
//         {
//             return false;
//         }
//         if (pages + arr[i] <= maxAllowedPgs)
//         {
//             pages += arr[i];
//         }
//         else
//         {
//             student++;
//             pages = arr[i];
//         }
//     }
//     //return student > m ? false : true;
//     return student <= m;
// }

// int bookAllocate(vector<int> &arr, int n, int m)
// {

//     if (m<n)
//     {
//         return -1;
//     }
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }

//     int ans = -1;
//     int st = *max_element(arr.begin(), arr.end()); 
//     int end = sum;

//     while (st <= end)
//     {
//         int mid = st + (end - st) / 2;

//         if (isvalid(arr, n, m, mid))
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//         else
//         {
//             st = mid + 1;
//         }
//     }
//     return ans;
// }

// int main()
// {

//     vector<int> arr = {2, 1, 3, 4};
//     int m = 2, n = 4;

//     int ans = bookAllocate(arr, n, m);
//     cout<<"the answer is "<<ans<<endl;

//     //cout << bookAllocate(arr, n, m) << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isvalid(vector<int> &arr, int n, int m, int maxAllowedPgs)
{
    int student = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPgs)
            return false;

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
    return student <= m;
}

int bookAllocate(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;

    int sum = 0;
    for (int x : arr)
        sum += x;

    int st = *max_element(arr.begin(), arr.end());
    int end = sum;
    int ans = -1;

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
    int n = 4, m = 2;

    cout << "The answer is " << bookAllocate(arr, n, m) << endl;
    return 0;
}
