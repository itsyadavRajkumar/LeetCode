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
	void pre(TreeNode *root)
	{
		if (root == NULL)
			return;
		cout << root->val << ' ';
		pre(root->left);
		pre(root->right);
	}
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> res;
		unordered_map<int, int> map;
		stack<pair<TreeNode *, bool>> s;
		s.push({root, false});
		while (!s.empty())
		{
			auto f = s.top();
			bool flag = true;
			while (!s.empty() && f.second)
			{

				int sum = f.first->val;
				if (f.first->left)
				{
					sum += f.first->left->val;
				}
				else if (f.first->right)
				{
					sum += f.first->right->val;
				}
				s.top().first->val = sum;
				map[sum]++;
				s.pop();
				flag = false;
			}
			if (flag)
			{
				if (f.first->left)
				{
					s.push({f.first->left, false});
				}
				else if (f.first->right)
				{
					s.push({f.first->right, false});
					s.top().second = true;
				}
				else
				{
					s.top().second = true;
				}
			}
		}
		pre(root);
		int mx = 0, cnt = 0, n = map[root->val];

		for (auto &it : map)
		{
			if (it.second > cnt)
			{
				cnt = it.second;
				mx = it.first;
			}
			if (n == it.second)
				n = -1;
			res.push_back(it.first);
		}
		if (n == -1)
		{
			res.clear();
			res.push_back(mx);
		}
		return res;
	}
};

int main() {

	return 0;
}