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
ll power(ll x, ll n) {ll result = 1; while (n) {if (n % 2 == 1) result = result * x; n = n / 2; x = x * x;} return result;}
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll lcm(ll a , ll b) {return (a * b) / gcd(a, b);}
ll BS(ll a[], ll s, ll n, ll val) {ll mid, beg = s, end = n - 1; while (beg <= end) {mid = (beg + end) / 2; if (val == a[mid]) {break;} else if (val > a[mid]) {beg = mid + 1;} else {end = mid - 1;}} return mid;}


class Solution {
	void rotation(vector<vector<int>>& mat)
	{
		int n = mat.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				swap(mat[i][j], mat[j][i]);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = n - 1, k = 0; j >= n / 2; --j, k++)
			{
				swap(mat[i][j], mat[i][k]);
			}
		}
	}
public:
	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		int t = 4;
		while (t--)
		{
			rotation(mat);
			if (mat == target)
				return true;
		}
		vvprint(mat);
		return false;
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		Solution ob;
		readll(n);
		vii mat(n, vi(n)), target(n, vi(n));
		vvcin(n, n, mat);
		vvcin(n, n, target);
		cout << ob.findRotation(mat, target) << '\n';
	}
	return 0;
}