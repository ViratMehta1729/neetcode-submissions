class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx= {1, -1, 0, 0};
        vector<int> dy= {0, 0, -1, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(!grid[i][j])
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty())
        {
            auto [u, v]= q.front(); q.pop();
            for(int index =0;index< 4;index++)
            {
                int uu = u+ dx[index];
                int vv = v+ dy[index];
                if(uu< 0 || vv< 0 || uu>=n || vv>=m || grid[uu][vv]==-1) continue;
                if(grid[uu][vv] > 1+ grid[u][v])
                {
                    grid[uu][vv] = 1+ grid[u][v];
                    q.push({uu, vv});
                }

            }
        }
        return ;
    }
};
