class PrefixTree {
public:
    class TreeNode{
        public:
        vector<TreeNode*> child;
        bool end;
        TreeNode(int k)
        {
            child.resize(26, 0);
            end = false;
        }
    };
    TreeNode* root;
    PrefixTree() {
        root = new TreeNode(26);
    }
    
    void insert(string word) {
        TreeNode* curr = root;
        for(auto x: word)
        {
            if(curr->child[x-'a']== NULL)
            {
                curr->child[x-'a'] = new TreeNode(26);
            }
            curr = curr->child[x-'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TreeNode* curr = root;
        for(auto x: word)
        {
            if(curr->child[x-'a']==NULL) return false;
            curr = curr->child[x-'a'];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr = root;
        for(auto x: prefix)
        {
            if(curr->child[x-'a']==NULL) return false;
            curr = curr->child[x-'a'];
        }
        return true;
    }
};
