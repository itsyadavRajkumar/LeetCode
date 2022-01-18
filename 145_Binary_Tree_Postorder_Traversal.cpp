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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<pair<TreeNode *, bool>> st;
		bool flag = true;
		TreeNode *node = root;
		while (flag)
		{
			if (node != NULL)
			{
				st.push({node, false});
				node = node->left;
			}
			else if (!st.empty())
			{
				while (!st.empty() && st.top().second)
				{
					res.push_back(st.top().first->val);
					st.pop();
				}
				if (!st.empty())
				{
					node = st.top().first;
					bool f = st.top().second;
					f = true;
					st.pop();
					st.push({node, f});
					node = node->right;
				}
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