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
		if (root == NULL) return 0;
		return 1 + max(height(root->left), height(root->right));
	}
	bool check(TreeNode *root)
	{
		if (root == NULL)
			return true;
		int lh = height(root->left);
		int rh = height(root->right);
		if (abs(lh - rh) > 1) return false;
		bool l = check(root->left);
		bool r = check(root->right);
		if (!l || !r) return false;
		return true;
	}
	bool isValid(TreeNode *root)
	{
		if (root == NULL) return true;
		unordered_map<TreeNode*, int> map;
		stack<pair<TreeNode *, bool>> st;
		TreeNode *node = root;
		bool pass = true;
		while (pass) {
			if (node) {
				st.push({node, false});
				node = node->left;
			}
			else if (!st.empty()) {
				while (!st.empty() && st.top().second) {
					auto t = st.top();
					int l = map[t.first->left];
					int r = map[t.first->right];
					map[t.first] = 1 + max(l, r);
					if (abs(l - r) > 1)
						return false;
					st.pop();
				}
				if (!st.empty()) {
					node = st.top().first->right;
					st.top().second = true;
				}
			}
			else pass = false;
		}
		return true;
	}
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;

		// return check(root);
	}
};

int main() {

	return 0;
}