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
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode *> q;
		q.push(root);
		int cnt = 0;
		while (!q.empty())
		{
			int n = q.size();
			cnt++;
			for (int i = 0; i < n; ++i)
			{
				TreeNode *f = q.front();
				if (f->left == NULL && f->right == NULL)
				{
					return cnt;
				}
				else if (f->left)
				{
					q.push(f->left);
				}
				if (f->right)
				{
					q.push(f->right);
				}
				q.pop();
			}
		}
		return cnt;
	}
};

int main() {

	return 0;
}