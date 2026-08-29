class Solution {
public:
    class Node{
        public:
        vector<Node*> child;
        int index;
        Node(int k)
        {
            child.assign(k, NULL);
            index = -1;
        }
    };
    Node* trie;
    vector<int> ret;
    void Tinsert(string &s, int k)
    {
        Node* curr = trie;
        for(auto x: s)
        {
            if(!curr->child[x-'a']) curr->child[x-'a'] = new Node(26);
            curr = curr->child[x-'a'];
        }
        curr->index = k;
        
        return ;
    }
    // bool Tfind(string s)
    // {
    //     Node* curr = trie;
    //     for(auto x: s)
    //     {
    //         if(!curr->child[x-'a']) return false;
    //         curr = curr->child[x-'a'];
    //     }
    //     return true;
    // }
    void dfs(vector<vector<char>>& board,int i, int j, vector<vector<int>> &vis, Node* curr)
    {
        int n = board.size();
        int m = board[0].size();
        vector<int> dx= {1, -1, 0, 0};
        vector<int> dy= {0, 0, -1, 1};
        vis[i][j] = 1;
        if(curr->index!=-1){ret.push_back(curr->index);curr->index=-1;}
        for(int index =0; index< 4; index++)
        {
            int ii = i + dx[index];
            int jj = j+ dy[index];
            if(ii<0 || jj< 0 || ii>=n || jj>=m || vis[ii][jj] || !curr->child[board[ii][jj]-'a']) continue;
            dfs(board, ii, jj, vis, curr->child[board[ii][jj]-'a']);
        }
        vis[i][j] = 0;
        return ;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        trie = new Node(26);
        for(int i =0;i< words.size(); i++)
        {
            Tinsert(words[i], i);
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                if(trie->child[board[i][j]-'a'])
                dfs(board, i, j, vis, trie->child[board[i][j]-'a']);
            }
        }
        vector<string> ans;
        for(auto x: ret)
        {
            ans.push_back(words[x]);
        }

        return ans;
    }
};
