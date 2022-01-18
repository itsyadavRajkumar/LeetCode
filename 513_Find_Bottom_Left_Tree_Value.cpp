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
	int findBottomLeftValue(TreeNode* root) {
		if (root == NULL)
			return -1;
		queue<TreeNode *> q;
		q.push(root);
		int res = -1;
		while (!q.empty())
		{
			queue<TreeNode *> r;
			while (!q.empty())
			{
				TreeNode *f = q.front();
				if (f->left)
				{
					r.push(f->left);
				}
				if (f->right)
				{
					r.push(f->right);
				}
				q.pop();
			}
			q = r;
			if (!q.empty())
				res = q.front()->val;
		}
		return res;
	}
};

int main() {

	return 0;
}