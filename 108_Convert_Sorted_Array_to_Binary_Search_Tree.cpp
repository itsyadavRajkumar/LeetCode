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
	TreeNode* create(vector<int> &nums, int start, int end) {
		if (start >= end) return nullptr;
		int mid = start + (end - start) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = create(nums, start, mid);
		root->right = create(nums, mid + 1, end);
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode *root = nullptr, *tail = NULL;
		root = create(nums, 0, nums.size());
		return root;
	}
};

void print(TreeNode* root) // print Binary tree
{
	if (root == NULL) return;
	queue<TreeNode* > q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* f = q.front();
		q.pop();
		cout << f->val << " : ";
		if (f->left != NULL)
		{
			cout << f->left->val << ' ';
			q.push(f->left);
		}
		if (f->right != NULL)
		{
			cout << f->right->val << ' ';
			q.push(f->right);
		}
		cout << '\n';
	}
}


int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	Solution ob;
	TreeNode *root = ob.sortedArrayToBST(nums);
	print(root);
	return 0;
}