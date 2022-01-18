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
#define vvcin(n, m, arr) repi(i, 0, n) repi(j, 0, m) cin >> arr[i][j];
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
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		// int mx = 0, n = nums.size(), cnt = 1, temp = 0;
		// bool flag = false;
		// if (n == 1)
		// {
		// 	return nums[0] == 1 ? 1 : 0;
		// }
		// for (int i = 1; i < n; ++i)
		// {
		// 	if (nums[i] || nums[i - 1])
		// 		temp++;
		// 	if (nums[i - 1] == 1 && nums[i] == 1)
		// 	{
		// 		cnt++;
		// 		flag = true;
		// 	}
		// 	else
		// 	{
		// 		mx = max(mx, cnt);
		// 		cnt = 1;
		// 	}
		// }
		// if (flag)
		// 	return max(mx, cnt);
		// else
		// {
		// 	if (temp > 0)
		// 		return 1;
		// 	return 0;
		// }

		int n = nums.size(), mx = INT_MIN;
		for (int i = 1; i < n; ++i)
		{
			if (nums[i])
			{
				nums[i] += nums[i - 1];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			mx = max(mx, nums[i]);
		}
		return mx;
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		Solution s;
		readll(n);
		vi arr(n);
		vcin(n, arr);
		cout << s.findMaxConsecutiveOnes(arr) << '\n';
	}
	return 0;
}