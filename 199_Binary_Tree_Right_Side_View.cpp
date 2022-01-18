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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode *> q;
		q.push(root);
		res.push_back(root->val);
		while (!q.empty())
		{
			queue<TreeNode *> r;
			while (!q.empty())
			{
				TreeNode *f = q.front();

				if (f->right)
				{
					r.push(f->right);
				}
				if (f->left)
				{
					r.push(f->left);
				}
				q.pop();
			}
			q = r;
			if (!q.empty())
				res.push_back(r.front()->val);
		}
		return res;
	}
};

int main() {

	return 0;
}