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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<vector<int>> s(2, vector<int>());
        auto dfs = [&](auto&& dfs, TreeNode* root, int f) {
            if (root == nullptr) return;
            if (root->left == nullptr && root->right == nullptr) {
                s[f].push_back(root->val);
            } else {
                dfs(dfs, root->left, f);
                dfs(dfs, root->right, f);
            }
        };
        dfs(dfs, root1, 0);
        dfs(dfs, root2, 1);
        return s[0] == s[1];
    }
};