#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL)
			return NULL;
		queue<Node *> q;
		q.push(root);
		while (!q.empty())
		{
			int n = q.size();
			Node *f = q.front();
			if (f->left)
				q.push(f->left);
			if (f->right)
				q.push(f->right);
			q.pop();
			for (int i = 1; i < n; ++i)
			{
				Node* curr = q.front();
				f->next = curr;
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
				f = f->next;
				q.pop();
			}
			f->next = NULL;
		}
		return root;
	}
};

int main() {

	return 0;
}