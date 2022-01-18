#include <bits/stdc++.h>
using namespace std;
#define ll long long

// class Solution {
// 	int cnt = 0;
// 	void path(vector<vector<int>>& obstacleGrid, int sr, int sc, int fr, int fc) {
// 		if (sr == fr && sc + 1 == fc)
// 		{
// 			cnt++;
// 			return;
// 		}
// 		else if (sc == fc || sr == fr)
// 		{
// 			return;
// 		}
// 		if (obstacleGrid[sr][sc] == 0)
// 		{
// 			obstacleGrid[sr][sc] = -1;
// 			path(obstacleGrid, sr, sc + 1, fr, fc);
// 			path(obstacleGrid, sr + 1, sc, fr, fc);
// 			obstacleGrid[sr][sc] = 0;
// 		}
// 	}
// public:
// 	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
// 		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
// 		path(obstacleGrid, 0, 0, n, m);
// 		return cnt;
// 	}
// };


class Solution {
	void path(vector<vector<int>> &obstacleGrid, vector<vector<int>>& res, int n, int m) {
		res[1][0] = 1;
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < m + 1; ++j)
			{
				if (obstacleGrid[i - 1][j - 1] == 1)
				{
					res[i][j] = 0;
				}
				else
				{
					res[i][j] = res[i - 1][j] + res[i][j - 1];
				}
			}
		}
		for (int i = 0; i < n + 1; ++i)
		{
			for (int j = 0; j < m + 1; ++j)
			{
				cout << res[i][j] << ' ';
			}
			cout << endl;
		}
	}
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		vector<vector<int> > res(n + 2, vector<int> (m + 2, 0));
		path(obstacleGrid, res, n, m);
		return res[n][m];
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> obstacleGrid(n, vector<int> (m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> obstacleGrid[i][j];
		}
	}
	Solution ob;
	cout << ob.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}