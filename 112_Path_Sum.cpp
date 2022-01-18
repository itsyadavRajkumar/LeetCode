#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Definition for a binary tree node.
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
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;
		queue<TreeNode* > q;
		q.push(root);
		while (!q.empty()) {
			auto f = q.front();
			if (f->val == targetSum && f->left && f->right)
				return true;
			if (f->left) {
				f->left->val += f->val;
				q.push(f->left);
			}
			if (f->right) {
				f->right->val += f->val;
				q.push(f->right);
			}
			q.pop();
		}
		return false;
	}
};

int main() {

	return 0;
}