/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *x_parent = nullptr, *y_parent = nullptr;
        int x_dep = 0, y_dep = 0;
        bool x_found = false, y_found = false;
        auto dfs = [&](auto&& dfs, TreeNode* cur, TreeNode* parent, int dep) {
            if (cur == nullptr) {
                return;
            }
            if (cur->val == x)
                tie(x_dep, x_parent, x_found) = tuple(dep, parent, true);
            if (cur->val == y)
                tie(y_dep, y_parent, y_found) = tuple(dep, parent, true);
            if (x_found && y_found)
                return;
            dfs(dfs, cur->left, cur, dep + 1);
            if (x_found && y_found)
                return;
            dfs(dfs, cur->right, cur, dep + 1);
        };
        dfs(dfs, root, nullptr, 0);
        return x_dep == y_dep && x_parent != y_parent;
    }
};