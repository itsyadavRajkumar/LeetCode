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
	void flatten(TreeNode *root, vector<TreeNode *>& helper)
	{
		if (root == nullptr) return;
		helper.push_back(root);
		flatten(root->left, helper);
		flatten(root->right, helper);
	}
public:
	void flatten(TreeNode* root) {
		if (root == nullptr) return;
		vector<TreeNode *> helper;
		flatten(root, helper);
		int n = helper.size();
		for (int i = 1; i < n; ++i)
		{
			helper[i - 1]->left = nullptr;
			helper[i - 1]->right = helper[i];
		}
	}
};

int main() {

	return 0;
}