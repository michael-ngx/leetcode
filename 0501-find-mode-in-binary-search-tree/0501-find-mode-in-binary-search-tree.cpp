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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> count;
        helper(root, count);

        vector<int> result;
        int max = 0;
        for (auto p : count) {
            if (p.second > max) {
                max = p.second;
                result = {p.first};
            } else if (p.second == max) {
                result.push_back(p.first);
            }
        }
        return result;
    }

    void helper(TreeNode* root, unordered_map<int,int>& count) {
        if (!root) return;
        helper(root->left, count);
        count[root->val]++;
        helper(root->right, count);
    }
};