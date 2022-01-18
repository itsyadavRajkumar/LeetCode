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


// TC : O(n+m)
// SC : O(n)

class Solution {
public:
	string minWindow(string s, string t) {
		string res = "";
		unordered_map<char, int> map1, map2;
		int m = t.size(), n = s.size();
		if (m > n)
			return "";
		for (int i = 0; i < m; ++i)
		{
			map2[t[i]]++;
		}
		int cnt = 0, i = 0, j = 0;
		deque<char> temp1, temp2;

		while (true)
		{
			bool f1 = true, f2 = true;

			while (i < n && cnt < m)
			{
				map1[s[i]]++;
				temp2.push_back(s[i]);
				if (map1[s[i]] <= map2[s[i]])
				{
					cnt++;
				}
				i++;
				f1 = false;
			}

			while (j < i && cnt == m)
			{
				if (temp1.empty() || temp1.size() > temp2.size())
				{
					temp1 = temp2;
				}
				if (map1[s[j]] == 1)
				{
					map1.erase(s[j]);
				}
				else
				{
					map1[s[j]]--;
				}
				if (map1[s[j]] < map2[s[j]])
				{
					cnt--;
				}
				temp2.pop_front();
				j++;
				f2 = false;
			}
			if (f1 && f2)
			{
				break;
			}
		}
		while (!temp1.empty())
		{
			res.push_back(temp1.front());
			temp1.pop_front();
		}
		return res;
	}
};


class Solution1 {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> mp;
		int tn = t.size();
		for (int i = 0; i < tn; i++) {
			mp[t[i]]++;
		}
		int charCnt = mp.size();
		int i = 0, j = 0;
		int sn = s.size();
		int len = INT_MAX;
		int strtIdx = 0;
		string result = "";
		while (j < sn) {
			//finding the character in map.
			if (mp.find(s[j]) != mp.end()) {
				mp[s[j]]--;
				if (mp[s[j]] == 0)
					charCnt--;
			}
			//character count > 0 then slide the winndow.
			if (charCnt > 0)
				j++;
			else if (charCnt == 0) {
				if (j - i + 1 < len) {
					len = min(len, j - i + 1);
					strtIdx = i;
					result = s.substr(strtIdx, len);
				}

				//minimize the window if possible
				while (charCnt == 0) {
					if (mp.find(s[i]) == mp.end()) {
						i++;

						if (j - i + 1 < len) {
							len = min(len, j - i + 1);
							strtIdx = i;
							result = s.substr(strtIdx, len);
						}
					}
					else {
						mp[s[i]]++;
						if (mp[s[i]] == 1) {
							i++;
							charCnt++;
						}
						else {
							i++;
							if (j - i + 1 < len) {
								len = min(len, j - i + 1);
								strtIdx = i;
								result = s.substr(strtIdx, len);
							}
						}
					}
				}
				j++;
			}

		}
		return (len == INT_MAX ? "" : result);
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		Solution ob;
		reads(s);
		reads(t);
		cout << ob.minWindow(s, t) << '\n';
	}
	return 0;
}