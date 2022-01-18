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
#define vvprint(arr) for (auto &i : arr) vprint(i)
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
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		int left = 0, right = m - 1;
		int top = 0, bottom = n - 1;
		vector<int> res;
		while (left <= right && top <= bottom)
		{
			for (int i = left; i < right + 1; ++i)
			{
				res.push_back(matrix[top][i]);
			}
			top++;
			for (int i = top; i < bottom + 1; ++i)
			{
				res.push_back(matrix[i][right]);
			}
			right--;
			if (top <= bottom)
				for (int i = right; i >= left; --i)
				{
					res.push_back(matrix[bottom][i]);
				}
			bottom--;
			if (left <= right)
				for (int i = bottom; i >= top; --i)
				{
					res.push_back(matrix[i][left]);
				}
			left++;
		}
		return res;
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		Solution ob;
		readi(n);
		readi(m);
		vii arr(n, vi(m));
		vvcin(n, m, arr);
		vi res = ob.spiralOrder(arr);
		vprint(res);
	}
	return 0;
}