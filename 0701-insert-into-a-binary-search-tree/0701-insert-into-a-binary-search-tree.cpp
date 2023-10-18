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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* on = root;
        while (on) {
            if (val > on->val) {
                if (!on->right) {
                    on->right = new TreeNode(val);
                    return root;
                } else {
                    on = on->right;
                }
            }
            else {
                if (!on->left) {
                    on->left = new TreeNode(val);
                    return root;
                } else {
                    on = on->left;
                }
            }
        }
        return root;
    }
};