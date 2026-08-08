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
    int ans = -1;
    bool inorder(TreeNode* root, int& k)
    {
        if(!root) return false;
        if(inorder(root->left, k)) return true;
        if(k==1)
        {
            ans= root->val;
            return true;
        }
        k--;
        if(inorder(root->right, k)) return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
