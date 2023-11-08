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
    // sum, count, good
    tuple<int,int,int> sum(TreeNode* root) {
        if (!root) return make_tuple(0, 0, 0);
        auto[x1,y1,z1] = sum(root->left);
        auto[x2,y2,z2] = sum(root->right);
        int sum = x1+x2+ root->val;
        int count = y1+y2+ 1;
        int good = z1+z2+ (sum/count == root->val ? 1 : 0);
        return make_tuple(sum, count, good);
    }
    int averageOfSubtree(TreeNode* root) {
        auto[a,b,res] = sum(root);
        return res;
    }
};