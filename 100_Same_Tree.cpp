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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        else if (p->val != q->val)
            return false;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *f1 = q1.front(), *f2 = q2.front();
            q1.pop(), q2.pop();
            if (f1->left == NULL && f2->left == NULL)
                true;
            else if (f1->left != NULL && f2->left != NULL)
            {
                int temp1 = f1->left->val;
                int temp2 = f2->left->val;
                if (temp1 == temp2)
                {
                    q1.push(f1->left);
                    q2.push(f2->left);
                }
                else return false;
            }
            else return false;

            if (f1->right == NULL && f2->right == NULL)
                true;
            else if (f1->right != NULL && f2->right != NULL)
            {
                int temp1 = f1->right->val;
                int temp2 = f2->right->val;
                if (temp1 == temp2)
                {
                    q1.push(f1->right);
                    q2.push(f2->right);
                }
                else return false;
            }
            else return false;
        }
        if (!q1.empty() || !q2.empty())
            return false;
        else return true;
    }
};

class Solution1 {
    bool check(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        else if (p->val != q->val)
            return false;
        return check(p->left, q->left) && check(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};

int main() {

    return 0;
}