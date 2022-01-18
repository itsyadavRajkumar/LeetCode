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

	int maxPathSum(TreeNode *root, int &mx)
	{
		if (root == NULL) return 0;
		int l = max(0, maxPathSum(root->left, mx));
		int r = max(0, maxPathSum(root->right, mx));
		mx = max(mx, l + r + root->val);
		return root->val + max(l, r);
	}
public:
	int maxPathSum(TreeNode * root) {
		if (root == NULL) return 0;
		int mx = INT_MIN;
		maxPathSum(root, mx);
		return mx;
	}
};

int main() {

	return 0;
}