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
#define ll long long
	ll merge(vector<int> &nums, ll l, ll m, ll r)
	{
		ll left = m - l + 1, right = r - m;
		vector<ll> temp1(left + 1, LONG_MAX), temp2(right + 1, LONG_MAX);
		for (ll i = 0; i < left; ++i)
		{
			temp1[i] = nums[i + l];
		}
		for (ll i = 0; i < right; ++i)
		{
			temp2[i] = nums[i + m + 1];
		}

		ll cnt = 0;
		for (ll i = left - 1, j = right - 1; j >= 0 && i >= 0;)
		{
			if (((double)temp1[i] / 2.0) > temp2[j])
			{
				cnt += j + 1;
				i--;
			}
			else j--;
		}

		ll j = 0, k = 0;
		for (ll i = l; i < r + 1; ++i)
		{
			if (temp2[k] >= temp1[j])
			{
				nums[i] = temp1[j++];
			}
			else
			{
				nums[i] = temp2[k++];
			}
		}
		return cnt;
	}

	ll mergeSort(vector<int> &nums, ll l, ll r)
	{
		if (l == r)
			return 0;
		ll m = (l + r) >> 1;
		ll res = 0;
		res += mergeSort(nums, l, m);
		res += mergeSort(nums, m + 1, r);
		res += merge(nums, l, m, r);
		return res;
	}

public:
	ll reversePairs(vector<int>& nums) {
		ll n = nums.size(), cnt = 0;
		cnt += mergeSort(nums, 0, n - 1);
		return cnt;
	}
};
class Solution1 {
public:
	int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
		if (end - begin <= 1)
			return 0;
		auto mid = begin + (end - begin) / 2;
		int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
		for (auto i = begin, j = mid; i != mid; ++i) {
			while (j != end and * i > 2L * *j)
				++j;
			count += j - mid;
		}
		inplace_merge(begin, mid, end);
		return count;
	}

	int reversePairs(vector<int>& nums) {
		return sort_and_count(nums.begin(), nums.end());
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
		cout << s.reversePairs(nums) << '\n';
		vprint(nums);
	}
	return 0;
}