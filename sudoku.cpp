#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {

	bool isValid(vector<vector<char>>& board, int x, int y, char val)
	{
		int m = board[0].size();
		for (int j = 0; j < m; ++j)
		{
			if (board[x][j] == val)
			{
				return false;
			}
		}
		int n = board.size();
		for (int i = 0; i < n; ++i)
		{
			if (board[i][y] == val)
			{
				return false;
			}
		}
		int smi = x / 3 * 3, smj = y / 3 * 3;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (board[smi + i][smj + j] == val)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool solve(vector<vector<char>>& board, int row, int col)
	{
		if (row == board.size())
		{
			return true;
		}
		if (col == board[0].size())
		{
			return solve(board, row + 1, 0);
		}
		if (board[row][col] != '.')
		{
			return solve(board, row, col + 1);
		}
		for (int i = 1; i < 10; ++i)
		{
			char val = '0' + i;
			if (isValid(board, row, col, val))
			{
				board[row][col] = val;
				ifsolve(board, row, col + 1)
				{
					return true;
				}
				board[row][col] = '.';
			}
		}
		return false;
	}
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		solve(board, 0, 0);
	}
};
int main() {
	vector<vector<char>> board(9, vector<char> (9));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
		}
	}
	Solution ob;
	ob.solveSudoku(board);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}