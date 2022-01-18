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
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) return 0;
		int sum = 0;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			auto f = q.front();
			if (!f->left && !f->right) {
				sum += f->val;
			}
			if (f->left) {
				f->left->val = f->left->val * 10 + f->val;
				q.push(f->left);
			}
			if (f->right) {
				f->right->val = f->right->val * 10 + f->val;
				q.push(f->right);
			}
			q.pop();
		}
		return sum;
	}
};

int main() {

	return 0;
}