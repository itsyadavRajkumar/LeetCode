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
	bool checkValid(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; ++i)
		{
			set<int> left;
			for (int j = 0; j < m; ++j)
			{
				int temp = matrix[i][j];
				left.insert(temp);
			}
			if (left.size() != n)
				return false;
		}
		for (int i = 0; i < n; ++i)
		{
			set<int> left;
			for (int j = 0; j < m; ++j)
			{
				int temp = matrix[j][i];
				left.insert(temp);
			}
			if (left.size() != n)
				return false;
		}
		return true;
	}
};

public int minSwaps(int[] data) {
	int count = 0;
	for (int d : data) {
		if (d == 1) {
			count++;
		}
	}

	int len = data.length;
	int min = Integer.MAX_VALUE;
	int start = 0;
	int end = 0;
	int zeros = 0;
	while (end < len) {
		if (data[end] == 0) {
			zeros++;
		}

		if (end - start + 1 > count) {
			if (data[start] == 0) {
				zeros--;
			}
			start++;
		}
		if (end - start + 1 == count) {
			min = Math.min(min, zeros);
		}
		end++;
	}
	return min;
}
int main() {
	fast_io;
	ll t = 1;
	cin >> t;
	while (t--) {
		// cout << solve() << '\n';

	}
	return 0;
}
