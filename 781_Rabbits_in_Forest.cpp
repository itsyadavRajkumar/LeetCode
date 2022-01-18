#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	int numRabbits(vector<int>& answers) {
		unordered_map<int, pair<int, int>> mp;
		int n = answers.size();
		for (int i = 0; i < n; ++i)
		{
			if (mp.find(answers[i]) != mp.end()) {
				pair<int, int> p = mp[answers[i]];
				if (p.first < p.second) {
					mp[answers[i]].first = p.first + 1;
					// mp[answers[i]] = { p.first + 1, answers[i] + 1};
				}
				else {
					// mp[answers[i]] = { p.first + 1, p.second + answers[i] + 1};
					mp[answers[i]].first = p.first + 1;
					mp[answers[i]].second = p.second + answers[i] + 1;
				}
			}
			else {
				mp[answers[i]] = {1, answers[i] + 1};
				// mp[answers[i]].first = 1;
				// mp[answers[i]].second = ;
			}
		}
		int cnt = 0;
		for (auto &i : mp)
		{
			pair<int, int> p = i.second;
			cnt += p.second;
			cout << i.first << ' ' << p.first << ' ' << p.second << endl;
		}
		return cnt;
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	Solution ob;
	cout << ob.numRabbits(v);
	return 0;
}