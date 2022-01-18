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
    bool check(TreeNode *root, long long mn, long long mx)
    {
        if (root == NULL)
            return true;
        if ((long long)(root -> val) <= mn || (long long)(root -> val) >= mx)
            return false;
        return check(root -> left, mn, (long long)(root -> val)) && check(root ->right, (long long)root -> val, mx);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL || (root -> left == NULL && root -> right == NULL))
            return true;
        return check(root, -1e18, 1e18);
    }
};

int main() {

    return 0;
}