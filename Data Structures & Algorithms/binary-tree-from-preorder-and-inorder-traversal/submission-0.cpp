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
    vector<int> pre;
    vector<int> in;
    map<int, int> mp;
    TreeNode* fun(vector<int> &pre, vector<int> & inor, int& index, int p, int q)
    {
        if(p > q) return NULL;
        if(p==q)
        {
            TreeNode* ans = new TreeNode(pre[index++]);
            return ans;
        }
        int val = pre[index++];
        TreeNode* ans = new TreeNode(val);
        ans->left = fun(pre, inor, index, p, mp[val]-1);
        ans->right = fun(pre, inor, index, mp[val]+1, q);
        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0; i < inorder.size(); i++)mp[inorder[i]] = i;
        int k =0;
        return fun(preorder, inorder, k,  0, preorder.size()-1);

    }
};
