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
    int ans =0;
    void fun(TreeNode* root, int k)
    {
        if(!root) return ;
        if(!root->left && !root->right)
        {
            if(root->val >= k)ans++;
            return ;
        }
        if(root->val >= k)ans++;
        fun(root->left, max(k, root->val));
        fun(root->right, max(k, root->val));
        return ;
    }
    int goodNodes(TreeNode* root) {
        fun(root, INT_MIN);
        return ans;
    }
};
