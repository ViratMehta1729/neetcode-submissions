class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int n = board.size();
        int m = board[0].size();
        vector<int> dx= {1, -1, 0, 0};
        vector<int> dy= {0, 0, -1, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i =0;i<n; i++)
        {
            for(int j =0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty())
        {
            auto [u, v]= q.front();q.pop();
            for(int index =0; index<4;index++)
            {
                auto uu = u+dx[index];
                auto vv = v+dy[index];
                if(uu<0 || vv<0 || uu>=n || vv>=m || vis[uu][vv] || board[uu][vv]=='X') continue;
                q.push({uu, vv});
                vis[uu][vv] = 1;
            }
        }
        for(int i =0;i< n;i++)
        {
            for(int j =0 ; j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]= 'X';
                }
            }
        }
        return ;
    }
};
