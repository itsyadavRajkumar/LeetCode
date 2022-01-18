#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
	int BST(int start, int end)
	{
		int res = 1;
		if (start > end)
		{
			return 0;
		}
		for (int i = start; i < end + 1; ++i)
		{
			int l = BST(start, i - 1);
			int r = BST(i + 1, end);
			res += l * r;
		}
		return res;
	}
public:
	int numTrees(int n) {
		if (n == 0)
			return 0;
		return BST(1, n);
	}
};

int main() {

	return 0;
}