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
    bool ans;
    int fun(TreeNode* root)
    {
        if(!root) return 0;
        int l = fun(root->left);
        int r = fun(root->right);
        if(abs(r-l) > 1) ans = false;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        fun(root);
        return ans;
    }
};
