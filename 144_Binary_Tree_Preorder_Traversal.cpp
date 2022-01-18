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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *> st;
		bool flag = true;
		TreeNode *node = root;
		while (flag)
		{
			if (node)
			{
				st.push(node);
				res.push_back(node->val);
				node = node->left;
			}
			else if (!st.empty())
			{
				node = st.top()->right;
				st.pop();
			}
			else
			{
				flag = false;
			}
		}
		return res;
	}
};

int main() {

	return 0;
}