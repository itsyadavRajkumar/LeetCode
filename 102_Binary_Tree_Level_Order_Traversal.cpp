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
	int height(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		return 1 + max(height(root->left), height(root->right));
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res(height(root));
		if (root == NULL)
			return res;
		queue<TreeNode *> q;
		q.push(root);
		int j = 0;
		while (!q.empty())
		{
			int n = q.size();
			bool flag = false;
			for (int i = 0; i < n; ++i)
			{
				TreeNode *f = q.front();
				res[j].push_back(f->val);
				if (f->left)
					q.push(f->left);
				if (f->right)
					q.push(f->right);
				q.pop();
				flag = true;
			}
			if (flag)
				j++;
		}
		return res;
	}
};

int main() {

	return 0;
}