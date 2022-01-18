#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
	bool cycle(vector<vector<int>> &edges, int node, int parent, vector<bool> &vis, vector<int> &res)
	{
		vis[node] = true;
		for (auto &child : edges[node])
		{
			if (!vis[child])
			{
				if (cycle(edges, child, node, vis, res))
					return true;

			}
			else if (child != parent)
			{
				res.push_back(parent);
				res.push_back(child);
				return true;
			}
		}
		return false;
	}
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> res;
		int v = edges.size();
		vector<bool> vis(v + 1, false);
		for (int i = 1; i < v + 1; ++i)
		{
			if (!vis[i]) continue;
			if (cycle(edges, i, -1, vis, res))
				return res;
		}
		return res;
	}
};

int main() {

	return 0;
}