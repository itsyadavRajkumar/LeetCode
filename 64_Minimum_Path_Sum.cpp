#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<long long>> t(n + 2, vector<long long> (m + 2, 0));

		for (int i = 1; i < n + 1; ++i)
		{
			t[i][1] = grid[i - 1][0] + t[i - 1][1];
		}
		for (int i = 1; i < m + 1; ++i)
		{
			t[1][i] = grid[0][i - 1] + t[1][i - 1];
		}

		for (int i = 2; i < n + 1; ++i)
		{
			for (int j = 2; j < m + 1; ++j)
			{
				t[i][j] = min(t[i - 1][j] + grid[i - 1][j - 1],
				              t[i][j - 1] + grid[i - 1][j - 1]);
			}
		}
		for (int i = 0; i < n + 1; ++i)
		{
			for (int j = 0; j < m + 1; ++j)
			{
				cout << t[i][j] << ' ';
			}
			cout << '\n';
		}
		return t[n][m];
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int> (m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	Solution ob;
	cout << ob.minPathSum(grid) << '\n';
	return 0;
}