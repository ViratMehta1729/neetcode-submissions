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
    bool fun(TreeNode* root, int k)
    {
        if(!root) return false;
        if(!root->left && !root->right && !(k- root->val)) return true;
        if(root->left && fun(root->left, k - root->val)) return true;
        if(root->right && fun(root->right, k - root->val)) return true;
        return false;

    }
    bool hasPathSum(TreeNode* root, int k) {
        return fun(root, k);
        
    }
};