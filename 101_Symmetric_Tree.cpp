#include <bits/stdc++.h>
using namespace std;
#define ll long long


// * Definition for a binary tree TreeNode.
// struct TreeNode {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(NULL), right(NULL) {}
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


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
				cout << "L : " << f->left->val << ' ';
				q.push(f->left);
			}
			if (f->right != NULL)
			{
				cout << ",R : " << f->right->val << ' ';
				q.push(f->right);
			}
			cout << '\n';
		}
	}
};

class Solution {
	TreeNode *helper(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *f = q.front();
			q.pop();
			if (f->left)
				q.push(f->left);
			if (f->right)
				q.push(f->right);
			TreeNode *temp = f->left;
			f->left = f->right;
			f->right = temp;
		}
		return root;
	}

	bool check(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == NULL && root2 == NULL)
			return true;
		else if (root1 != NULL && root2 == NULL)
			return false;
		else if (root1 == NULL && root2 != NULL)
			return false;
		queue<TreeNode *> q1, q2;
		q1.push(root1);
		q2.push(root2);
		while (!q1.empty() && !q2.empty())
		{
			TreeNode *f1 = q1.front();
			TreeNode *f2 = q2.front();
			if ((f1 != NULL && f2 != NULL) && (f1->val != f2->val))
				return false;
			if (f1->left == NULL && f2->left == NULL)
				true;
			else if (f1->left != NULL && f2->left != NULL)
			{
				q1.push(f1->left);
				q2.push(f2->left);
			}
			else return false;
			if (f1->right == NULL && f2->right == NULL)
				true;
			else if (f1->right != NULL && f2->right != NULL)
			{
				q1.push(f1->right);
				q2.push(f2->right);
			}
			else return false;
			q1.pop();
			q2.pop();
		}
		return true;
	}
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		BinaryTree ob;
		ob.print(root->right);
		cout << endl;
		ob.print(root->left);
		TreeNode *mirror = root->right;
		mirror = helper(mirror);
		cout << endl;
		ob.print(mirror);
		cout << endl;
		ob.print(root->left);
		return check(root->left, mirror);
	}
};


int main() {
	BinaryTree bt;
	TreeNode *root = bt.create();
	// cout << "Tree : \n" ;
	// bt.print(root);
	Solution ob;
	// cout << endl << endl;
	cout << ob.isSymmetric(root) << '\n';
	// cout << "TreePathsSum : \n";
	// bt.treePathsSum(root);
	// bt.print(root);

	return 0;
}