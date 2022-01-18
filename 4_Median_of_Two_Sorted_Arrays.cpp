#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ll long long
#define ull unsigned long long
#define readi(x) int x; cin >> x
#define readll(x) ll x; cin >> x
#define reads(s) string s; cin >> s
#define rep(a, b) for (ll i = a; i < b; ++i)
#define repi(i, a, b) for (ll i = a; i < b; ++i)
#define repd(i, a, b) for (ll i = a; i > b; --i)
#define all(x) (x).begin(), (x).end()
#define init_arr readll(n); vll arr(n); rep(0, n) cin >> arr[i];
#define vprint(i) for (auto &j : i) cout << j << ' '; nl
#define mpprint(mp) for (auto &i : mp) { cout << i.ff << ' ' << i.ss << '\n'; }
#define vvprint(arr) for (auto &i : arr) { vprint(i) }
#define vvcin(n, m, arr) rep(i, 0, n) repi(j, 0, m) cin >> arr[i][j];
#define vcin(n, arr) rep(0, n) cin >> arr[i];
#define umcll unordered_map<char, ll >
#define umsll unordered_map<string, ll >
#define umll unordered_map<ll, ll >
#define print(num) cout << num << '\n';
#define mpcll map<char, ll >
#define mpsll map<string, ll >
#define mpll map<ll, ll >
#define nl cout << '\n';
#define inf (1LL << 60)
#define vll vector<ll >
#define vi vector<int >
#define vii vector<vi >
#define vs vector<string >
#define vss vector<vs >
#define vb vector<bool >
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1e9 + 7
#define ff first
#define ss second
#define N 1e6

class Solution {
#define ll long long

	double solve(vector<int>& nums1, vector<int>& nums2)
	{
		ll n1 = nums1.size(), n2 = nums2.size();
		ll n = n1 + n2;
		ll start = 0, end = n1;
		while (start <= end)
		{
			ll mid = start + (end - start) / 2;
			ll last = (n + 1) / 2 - mid;

			ll min1 = mid == 0 ? LONG_MIN : nums1[mid - 1];
			ll max1 = mid == n1 ? LONG_MAX : nums1[mid];
			ll min2 = last == 0 ? LONG_MIN : nums2[last - 1];
			ll max2 = last == n2 ? LONG_MAX : nums2[last];

			if (min1 <= max2 && min2 <= max1)
			{
				if (n & 1)
				{
					ll mx = max(min2, min1);
					return (double)mx;
				}
				else
				{
					ll mx = max(min2, min1);
					ll mn = min(max2, max1);
					return (double)(mx + mn) / 2.0;
				}
			}
			else if (min1 > max2)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		return -1.0;
	}

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		ll n1 = nums1.size(), n2 = nums2.size();
		if (n1 > n2)
		{
			return solve(nums2, nums1);
		}
		else
		{
			return solve(nums1, nums2);
		}
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		readll(n);
		readll(m);
		vi nums1(n), nums2(m);
		vcin(n, nums1);
		vcin(m, nums2);
		Solution ob;
		cout << ob.findMedianSortedArrays(nums1, nums2) << '\n';
	}
	return 0;
}