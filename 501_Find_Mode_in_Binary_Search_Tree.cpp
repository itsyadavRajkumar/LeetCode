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
	void findMode(TreeNode *root, unordered_map<int, int>& map)
	{
		if (root == nullptr) return;
		findMode(root->left, map);
		findMode(root->right, map);
		map[root->val]++;
	}
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;
		unordered_map<int, int> map;
		findMode(root, map);
		int fre = 0;
		for (auto &it : map)
			fre = max(fre, it.second);
		for (auto &it : map)
			if (fre == it.second)
				res.push_back(it.first);
		return res;
	}
};

int main() {

	return 0;
}