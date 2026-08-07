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
    vector<int> ans;
    void preorder(TreeNode* root, int k)
    {
        if(!root) return ;
        if(!root->left && !root->right)
        {
            if(ans.size() < k)ans.push_back(root->val);
            return ;
        }
        if(ans.size() < k)ans.push_back(root->val);
        preorder(root->right, k+1);
        preorder(root->left, k+1 );
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        preorder(root, 1);
        return ans;
    }
};
