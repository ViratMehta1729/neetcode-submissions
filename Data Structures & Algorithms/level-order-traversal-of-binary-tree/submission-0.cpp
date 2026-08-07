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
    vector<vector<int>> ans;
    void push(int val, int k)
    {
        if(ans.size()>=k)
        {
            ans[k-1].push_back(val);
        }
        else
        {
            ans.push_back({val});
        }
        return ;
    }
    void inorder(TreeNode* root, int k)
    {
        if(!root) return ;
        if(!root->left && !root->right)
        {
            push(root->val, k);
            return ;
        }
         push(root->val, k);
        inorder(root->left, k+1);
        inorder(root->right, k+1);
        return ;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        inorder(root, 1);
        return ans;
        
    }
};
