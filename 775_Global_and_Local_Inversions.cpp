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
	int merge(vector<int> &nums, int l, int m, int r)
	{
		int global = 0;
		int left = m - l + 1, right = r - m;
		vector<int > temp1(left + 1, INT_MAX), temp2(right + 1, INT_MAX);
		for (int i = 0; i < left; ++i)
		{
			temp1[i] = nums[i + l];
		}
		for (int i = 0; i < right; ++i)
		{
			temp2[i] = nums[i + m + 1];
		}
		int j = 0, k = 0;
		for (int i = l; i < r + 1; ++i)
		{
			if (temp1[j] > temp2[k])
			{
				nums[i] = temp2[k++];
				global += left - j;
			}
			else
			{
				nums[i] = temp1[j++];
			}
		}
		return global;
	}

	int mergeSort(vector<int> &nums, int l, int r)
	{
		int global = 0;
		if (l == r)
			return 0;
		int m = (l + r) / 2;
		global += mergeSort(nums, l, m);
		global += mergeSort(nums, m + 1, r);
		global += merge(nums, l, m, r);
		return global;
	}
public:
	bool isIdealPermutation(vector<int>& nums) {
		int n = nums.size(), local = 0;
		for (int i = 1; i < n; ++i)
		{
			if (nums[i - 1] > nums[i])
				local++;
		}
		int global = mergeSort(nums, 0, n - 1);
		return global == local;
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		Solution s;
		readll(n);
		vi nums(n);
		vcin(n, nums);
		cout << s.isIdealPermutation(nums) << '\n';
	}
	return 0;
}