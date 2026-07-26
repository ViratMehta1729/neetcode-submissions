class Solution {
public:
    vector<vector<int>> used;
    bool dfs(vector<vector<char>>& board, string &word, int index, int i, int j)
    {
        if(index==word.size()) return true;
        if(board[i][j]!=word[index]) return false;
        if(index+1 == word.size()) return true;
        vector<int> dx= {1, -1, 0, 0};
        vector<int> dy= {0, 0, -1, 1};
        used[i][j] = 1;
        for(int k =0;k< 4;k++)
        {
            int ii = i+dx[k];
            int jj = j+dy[k];
            if(ii<0 || jj<0 || ii>= board.size() || jj>=board[0].size() || used[ii][jj]) continue;
            if(dfs(board, word, index+1, ii, jj)) return true;
        } 
        used[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        used.resize(n, vector<int>(m, 0));
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
