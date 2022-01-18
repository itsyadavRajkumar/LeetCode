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
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		stack<pair<TreeNode* , bool>> st;
		TreeNode *node = root;
		int sum = 0;
		vector<int> temp;
		bool flag = true;
		while (flag)
		{
			if (node)
			{
				sum += node->val;
				temp.push_back(node->val);
				if (sum == targetSum && !(node->left) && !(node->right))
				{
					res.push_back(temp);
				}
				st.push({node, false});
				node = node->left;
			}
			else if (!st.empty())
			{
				while (!st.empty() && st.top().second)
				{
					sum -= st.top().first->val;
					temp.pop_back();
					st.pop();
				}
				if (!st.empty())
				{
					node = st.top().first->right;
					st.top().second = true;
				}
			}
			else flag = false;
		}
		return res;
	}
};

int main() {

	return 0;
}