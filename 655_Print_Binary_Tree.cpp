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
	vector<vector<string>> printTree(TreeNode* root) {
		vector<vector<string>> res;
	}
};

bool ispar(string s)
{
	stack<char>st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		} else if (st.empty()) {
			return false;
		} else if (s[i] == ')') {
			if (st.top() == '(')
				st.pop();
			else return false;
		} else if (s[i] == '}') {
			if (st.top() == '{')
				st.pop();
			else return false;
		} else if (s[i] == ']') {
			if (st.top() == '[')
				st.pop();
			else return false;
		}

	}
	if (st.empty())
		return true;
	else
		return false;
}

};

int main() {

	return 0;
}