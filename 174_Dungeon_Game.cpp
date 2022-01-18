#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

	void solve(vector<vector<int>>& dungeon, vector<vector<int>>& t)
	{
		int n = dungeon.size(), m = dungeon[0].size();
		for (int i = 1; i < n + 1; ++i)
		{
			t[i][1] = t[i - 1][1] + dungeon[i - 1][0];
		}
		for (int i = 1; i < m + 1; ++i)
		{
			t[1][i] = t[1][i - 1] + dungeon[0][i - 1];
		}

		for (int i = 2; i < n + 1; ++i)
		{
			for (int j = 2; j < m + 1; ++j)
			{
				int x = t[i - 1][j], y = t[i][j - 1];
				if (x < 0 and y < 0)
				{
					t[i][j] = max(x + dungeon[i - 1][j - 1], y + dungeon[i - 1][j - 1]);
				}
				else
				{
					t[i][j] = min(x + dungeon[i - 1][j - 1], y + dungeon[i - 1][j - 1]);
				}
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
	}
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size(), m = dungeon[0].size();
		vector<vector<int>> t(n + 1, vector<int > (m + 1, 0));
		solve(dungeon, t);
		if (t[n][m] < 0)
			return abs(t[n][m]) + 1;
		else return 1;
	}
};

int main() {
	Solution ob;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dungeon(n, vector<int > (m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> dungeon[i][j];
		}
	}
	cout << ob.calculateMinimumHP(dungeon) << endl;
	return 0;
}