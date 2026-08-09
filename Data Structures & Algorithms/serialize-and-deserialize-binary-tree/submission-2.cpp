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

class Codec {
public:
    vector<int> pre;
    vector<int> in;
    // preorder traversal of a tree
    void preorder(TreeNode* root)
    {
        if(!root) 
        {
            pre.push_back(INT_MIN);
            return;
        }
        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    // inorder traversal of a tree
    void inorder(TreeNode* root)
    {
        if(!root) 
        {
            in.push_back(INT_MIN);
            return;
        }
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preorder(root);
        inorder(root);
        int n = pre.size();
        string str="@";
        str+=to_string(n);
        for(auto x: pre)
        {
            str+='@';
            str+=to_string(x);
        }
        for(auto x: in)
        {
            str+='@';
            str+=to_string(x);
        }
        return str;
    }
    TreeNode* helper(vector<int> &pre, int &index)
    {
        if(pre.size()==0 || pre[index]==INT_MIN )
        {
            index++;
            return NULL;
        }
        int val = pre[index++];
        TreeNode* ans = new TreeNode(val);
        ans->left = helper(pre, index);
        ans->right = helper(pre, index);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<int> temp;
        int i =1;
        int n = data.size();
        while(i<n)
        {
            string str ;
            while(i< n && data[i]!='@')
            {
                str+=data[i];
                i++;
            }
            temp.push_back(stoi(str));
            i++;
        }
        int k = temp[0];
        vector<int> pre(k);
        vector<int> in(k);
        i =1;
        int kk = k;
        int index = 0;
        while(kk--)
        {
            pre[index++]=temp[i++];
        }
        kk= k;
        index = 0;
        while(kk--)
        {
            in[index++]= temp[i++];
        }
        index  =0;
        return helper(pre, index);
    }
};
