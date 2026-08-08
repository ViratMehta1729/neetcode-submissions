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
    int ans = true;
    pair<int, int> fun(TreeNode* root)
    {
        if(!root)
        {
            return {INT_MAX, INT_MIN};
        }
        if(!root->left && !root->right)
        {
            return {root->val, root->val};
        }
        auto [p, q] = fun(root->left);
        auto [r, s] = fun(root->right);
        if(q < root->val && r > root->val)
        {

        }
        else
        {
            ans= false;
        }
        return {min({p, r, root->val}), max({q, s, root->val})};
    }
    bool isValidBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};
