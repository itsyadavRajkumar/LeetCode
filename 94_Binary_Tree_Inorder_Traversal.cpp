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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode *> st;
		vector<int> res;
		TreeNode *node = root;
		bool flag = true;
		while (flag)
		{
			if (node != NULL)
			{
				st.push(node);
				node = node->left;
			}
			else if (!st.empty())
			{
				res.push_back(st.top()->val);
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