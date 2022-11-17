// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool isSameTree = true;
        dfs(p, q, isSameTree);
        return isSameTree;
    }

    void dfs(TreeNode *p, TreeNode *q, bool &isSameTree) {
        if (!isSameTree) {
            return;
        }
        if (p == nullptr && q == nullptr) {
            return;
        } else if (p == nullptr || q == nullptr) {
            isSameTree = false;
            return;
        }

        if (p->val != q->val) {
            isSameTree = false;
        }

        dfs(p->left, q->left, isSameTree);
        dfs(p->right, q->right, isSameTree);
    }
};
