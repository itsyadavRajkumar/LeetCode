// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution
{
    typedef long long ll;
    bool Part(int arr[], ll mx, ll N, ll M)
    {
        ll sum = 0, cnt = 1;
        for (ll i = 0; i < N; ++i)
        {
            sum += arr[i];
            if (sum > mx)
            {
                cnt++;
                sum = 0;
                sum += arr[i];
            }
        }
        return cnt <= M;
    }

    ll BS(int arr[], ll st, ll hi, ll N, ll M)
    {
        ll res = -1;
        while (st <= hi)
        {
            ll m = st + (hi - st) / 2;
            if (Part(arr, m, N, M) == true)
            {
                res = m;
                hi = m - 1;
            }
            else
            {
                st = m + 1;
            }
        }
        return res;
    }
public:
    //Function to find minimum number of pages.
    ll findPages(int A[], ll N, ll M)
    {
        //code here
        if (M > N)
        {
            return -1;
        }
        int sum = 0, mn = LONG_MIN;
        for (ll i = 0; i < N; ++i)
        {
            sum += A[i];
            mn = max(mn, A[i]);
        }
        return BS(A, mn, sum, N, M);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends