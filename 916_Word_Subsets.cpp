#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
		vector<string> res;
		int n = words1.size(), m = words2.size();
		unordered_map<char, int> map;
		for (int i = 0; i < m; ++i)
		{
			int m1 = words2[i].size();
			unordered_map<char, int> helper;
			for (int j = 0; j < m1; ++j)
				helper[words2[i][j]]++;
			for (auto &it : helper)
			{
				if (map.find(it.first) != map.end())
				{
					map[it.first] = max(it.second, map[it.first]);
				}
				else if (map.find(it.first) == map.end())
					map[it.first] = it.second;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			unordered_map<char, int> mp = map;
			int n1 = words1[i].size();
			for (int j = 0; j < n1; ++j)
			{
				if (mp.find(words1[i][j]) != mp.end())
				{
					mp[words1[i][j]]--;
					if (mp[words1[i][j]] == 0)
						mp.erase(words1[i][j]);
				}
			}
			if (mp.size() == 0)
				res.push_back(words1[i]);
		}
		return res;
	}
};

int main() {

	return 0;
}