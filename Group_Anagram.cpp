#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ll long long
#define ull unsigned long long
#define readi(x) int x; cin>>x
#define readll(x) ll x; cin>>x
#define reads(s) string s; cin>>s
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repi(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>b;--i)
#define all(x) (x).begin(), (x).end()
#define vprint(i) for(auto &j:i) cout<<j<<' '; nl
#define vvprint(arr) for(auto &i:arr) { vprint(i) }
#define vvcin(n,m,arr) rep(i,0,n) rep(j,0,m) cin>>arr[i][j];
#define vcin(n,arr) rep(i,0,n) cin>>arr[i];
#define umcll unordered_map<char, ll >
#define umsll unordered_map<string, ll >
#define umll unordered_map<ll, ll >
#define print(num) cout<<num<<'\n';
#define mpcll map<char, ll >
#define mpsll map<string, ll >
#define mpll map<ll, ll >
#define nl cout<<'\n';
#define inf (1LL<<60)
#define vll vector<ll >
#define vi vector<int >
#define vii vector<vi >
#define vs vector<string >
#define vss vector<vs >
#define vb vector<bool >
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1e9+7
#define ff first
#define ss second
#define N 1e6

/*
	Example 1:

	Input: strs = ["eat","tea","tan","ate","nat","bat"]
	Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

	Example 2:

	Input: strs = [""]
	Output: [[""]]
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string >> res;
		map<map<char, int>, vector<string> > mp;
		for (int i = 0; i < strs.size(); ++i) {
			map<char, int> temp;
			for (int j = 0; j < strs[i].size(); ++j)
				temp[strs[i][j]]++;
			vector<string > temp1;
			temp1.push_back(strs[i]);
			if (mp.find(temp) != mp.end())
				mp[temp].push_back(strs[i]);
			else
				mp.insert({temp, temp1});
		}
		for (auto &i : mp)
			res.push_back(i.second);
		return res;
	}
};

int main() {
	fast_io;

	return 0;
}