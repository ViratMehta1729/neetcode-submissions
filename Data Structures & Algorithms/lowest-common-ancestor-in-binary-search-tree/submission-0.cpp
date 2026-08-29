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
    TreeNode* ans;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return ;
        if(root->val>=p->val && root->val <=q->val) {ans = root;return;}
        if(root->val  < p->val)
        {
            dfs(root->right, p, q);
        }
        else
        {
            dfs(root->left, p, q);
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)swap(p, q);
        dfs(root, p, q);
        return ans;
    }
};
