#include <bits/stdc++.h>
using namespace std;
#define ll long long


// * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	vector<TreeNode*> helper(int start, int end)
	{
		vector<TreeNode*> node;
		if (start > end)
		{
			node.push_back(NULL);
			return node;
		}
		for (int i = start; i < end + 1; ++i)
		{
			vector<TreeNode*> l = helper(start, i - 1);
			vector<TreeNode*> r = helper(i + 1, end);
			for (auto &itl : l)
			{
				for (auto &itr : r)
				{
					TreeNode *root = new TreeNode(i, itl, itr);
					node.push_back(root);
				}
			}
		}
		return node;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n == 0)
		{
			res.push_back(NULL);
			return res;
		}
		return helper(1, n);
	}
};

int main() {

	return 0;
}