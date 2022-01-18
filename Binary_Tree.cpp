#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TreeNode
{
public:
	int val;
	TreeNode* left, *right;
	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

class BinaryTree {
private:
	ll sum = 0, res = 0;
public:
	TreeNode* create() // create Binary Tree
	{
		ll rootval; cin >> rootval;
		TreeNode* root = new TreeNode(rootval);
		queue<TreeNode* > pendingTreeNode;
		pendingTreeNode.push(root);
		while (pendingTreeNode.size() != 0)
		{
			TreeNode* f = pendingTreeNode.front();
			pendingTreeNode.pop();
			ll leftval; cin >> leftval;

			ll rightval; cin >> rightval;
			if (leftval != -1)
			{
				TreeNode* leftRoot = new TreeNode(leftval);
				pendingTreeNode.push(leftRoot);
				f->left = leftRoot;
			}
			if (rightval != -1)
			{
				TreeNode* rightRoot = new TreeNode(rightval);
				pendingTreeNode.push(rightRoot);
				f->right = rightRoot;
			}
		}
		return root;
	}

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

	ll height(TreeNode *root) // Height of Binary Tree
	{
		if (!root) return 0;
		return 1 + max(height(root->left), height(root->right));
	}

	ll treePathsSum(TreeNode *root)
	{
		if (root == NULL) return 0;
		res = res * 10 + root->val;
		root->val = res;
		if (root->left == NULL and root->right == NULL)
			sum += root->val;
		treePathsSum(root->left);
		res = root->val;
		treePathsSum(root->right);
		return sum;
	}

	ll diameter(TreeNode* root) // Diameter Of Bianry Tree
	{
		if (!root) return 0;
		ll ld = diameter(root->left);
		ll rd = diameter(root->right);
		ll lft = height(root->left);
		ll rght = height(root->right);
		return max({1 + lft + rght, ld, rd});
	}

	vector<int> leftView(TreeNode *root)
	{
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode *> q;
		q.push(root);
		res.push_back(root->val);
		while (!q.empty())
		{
			queue<TreeNode *> temp;
			while (!q.empty())
			{
				TreeNode *f = q.front();
				q.pop();
				if (f->left)
				{
					temp.push(f->left);
				}
				if (f->right)
				{
					temp.push(f->right);
				}
			}
			q = temp;
			if (!q.empty())
				res.push_back(q.front()->val);
		}
		return res;
	}

	vector<int> topView(TreeNode *root)
	{
		vector<int> res;
		if (root == NULL)
			return res;
		deque<TreeNode *> q;
		q.push_back(root);
		// res.push_back(root->val);
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; ++i)
			{
				auto val = q.front();
				q.pop_front();
				if (i == 0)
				{
					res.push_back(val->val);
				}
				else if (i == n - 1 && n > 1)
				{
					res.push_back(val->val);
				}
				if (val->left)
					q.push_back(val->left);
				if (val->right)
					q.push_back(val->right);
			}
		}
		return res;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> res;
		unordered_map<int, int> map;
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
				auto f = st.top();
				while (!st.empty() && st.top().second)
				{
					f = st.top();
					int sum = f.first->val;
					if (f.first->left)
					{
						sum += f.first->left->val;
					}
					if (f.first->right)
					{
						sum += f.first->right->val;
					}
					st.top().first->val = sum;
					map[sum]++;
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

		// print(root);

		int mx = 0, cnt = 0;

		for (auto &it : map)
		{
			cnt = max(cnt, it.second);
		}
		for (auto &it : map)
		{
			if (it.second == cnt)
				res.push_back(it.first);
		}
		return res;
	}

	bool isBalanced(TreeNode *root)
	{
		if (root == NULL) return true;
		unordered_map<TreeNode*, int> map;
		stack<pair<TreeNode *, bool>> st;
		TreeNode *node = root;
		vector<int> res;
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
					cout << t.first->val << ' ' << map[t.first] << '\n';
					if (abs(l - r) > 1)
						return false;
					st.pop();
					res.push_back(t.first->val);
				}
				if (!st.empty()) {
					node = st.top().first->right;
					st.top().second = true;
				}
			}
			else pass = false;
		}
		// for (auto it : map)
		// 	cout << it.first->val << ' ' << it.second << '\n';
		// cout << '\n';
		// cout << map.size();
		// for (auto &it : res)
		// 	cout << it << ' ';
		// cout << '\n';
		return true;
	}
};

class Solution {
	vector<int> insert(TreeNode *root, unordered_map<TreeNode*, pair<TreeNode*, int>>& map)
	{
		TreeNode *node = root;
		vector<int> res;
		int data = INT_MIN;
		while (node->val != data)
		{
			res.push_back(node->val);
			pair<TreeNode*, int> p = map[node];
			data = node->val;
			node = p.first;
		}
		reverse(res.begin(), res.end());
		return res;
	}
public:
	vector<vector<int>> pathSum1(TreeNode* root, int targetSum) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		// unordered_map<TreeNode*, pair<TreeNode*, int>> map;
		// queue<TreeNode *> q, temp;
		// q.push(root);
		// map[root] = {root, root->val};
		// while (!q.empty()) {
		// 	auto f = q.front();
		// 	if (f->left == NULL && f->right == NULL)
		// 	{
		// 		temp.push(f);
		// 	}
		// 	if (f->left)
		// 	{
		// 		q.push(f->left);
		// 		pair<TreeNode*, int> p = map[f];
		// 		map[f->left] = {f, p.second + f->left->val};
		// 	}
		// 	if (f->right)
		// 	{
		// 		pair<TreeNode*, int> p = map[f];
		// 		q.push(f->right);
		// 		map[f->right] = {f, p.second + f->right->val};
		// 	}
		// 	q.pop();
		// }
		// // cout << temp.size() << '\n';
		// while (!temp.empty())
		// {
		// 	auto f = temp.front();
		// 	pair<TreeNode*, int> p = map[f];
		// 	// cout << f->val << ' ' << p.first->val << ' ' << p.second << '\n';
		// 	if (p.second == targetSum)
		// 	{
		// 		// cout << p.first->val << ' ';
		// 		vector<int> t = insert(f, map);
		// 		res.push_back(t);
		// 	}
		// 	temp.pop();
		// }
		// return res;

	}
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

// 5 4 8 11 13 4 7 2 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
	BinaryTree bt;
	TreeNode *root = bt.create();
	Solution ob;
	// bt.print(root);
	vector<vector<int>> res = ob.pathSum(root, 22);
	for (auto &it : res)
	{
		for (auto &j : it)
			cout << j << ' ';
		cout << '\n';
	}
	// cout << bt.isBalanced(root) << '\n';
	// cout << "Tree : \n" ;
	// bt.print(root);
	// cout << '\n';
	// vector<int> mostFre = bt.findFrequentTreeSum(root);
	// for (auto &it : mostFre)
	// 	cout << it << ' ';
	// cout << "TreePathsSum : \n";
	// bt.treePathsSum(root);
	// bt.print(root);
	// cout << "Height : " << bt.height(root) << '\n';
	// cout << "Diameter : " << bt.diameter(root) << '\n';
	// vector<int> leftview = bt.leftView(root);
	// vector<int> topview = bt.topView(root);
	// for (auto &it : topview)
	// 	cout << it << ' ';
	// cout << '\n';
	return 0;
}