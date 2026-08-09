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
    map <TreeNode* , int> mp;
    int ans = INT_MIN;
    int fun(TreeNode* root)
    {
        if(!root) return 0;
        if(!root->left && !root->right)
        {
            mp[root] = root->val;
            ans= max(ans, root->val);
            return mp[root];
        }
        int l = fun(root->left);
        int r = fun(root->right);
        int res = max(max(root->val, r+root->val), max(root->val, l+root->val));
        ans = max(ans, max({root->val, l+ root->val, r+ root->val, l+r+root->val}));
        mp[root] = res;
        return res;
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};
