/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        auto drummy = new TreeNode();
        auto cur = drummy;
        auto inorder = [&](auto&& inorder, TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            inorder(inorder, node->left);
            cur->right = node;
            node->left = nullptr;
            cur = node;
            inorder(inorder, node->right);
        };
        inorder(inorder, root);
        return drummy->right;
    }
};