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
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return NULL;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *f = q.front();
			TreeNode *Left = f->left;
			TreeNode *Right = f->right;
			f->left = Right;
			f->right = Left;
			q.pop();
			if (Right)
				q.push(Right);
			if (Left)
				q.push(Left);
		}
		return root;
	}
};

int main() {

	return 0;
}