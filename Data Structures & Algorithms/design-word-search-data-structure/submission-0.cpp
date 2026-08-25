class WordDictionary {
public:
    class TreeNode{
    public:
        vector<TreeNode*> child;
        bool isEnd;
        TreeNode(int k)
        {
            child.resize(k);
            isEnd = false;
        }
    };
    TreeNode* root;
    WordDictionary() {
        root = new TreeNode(26);
    }
    bool dfs(string &word, int index, TreeNode* curr)
    {
        if(word.size()==index) return !curr ? false : curr->isEnd;
        if(curr==NULL) return false;
        if(word[index]!='.')
        {
            if(curr->child[word[index]-'a']==NULL) return false;
            return dfs(word, index+1, curr->child[word[index]-'a']);
        }
        for(int i=0;i<26; i++)
        {
            if (dfs(word, index+1, curr->child[i])) return true;
        }
        return false;
    }
    void addWord(string word) {
        TreeNode* curr = root;
        for(auto x: word)
        {
            if(curr->child[x-'a']==NULL)
            {
                curr->child[x-'a']= new TreeNode(26);
               
            }
            curr = curr->child[x-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
