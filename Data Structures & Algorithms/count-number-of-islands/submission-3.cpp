class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans =0;
        for(int i =0; i < n; i++)
        {
            for(int j =0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while(!q.empty())
                    {
                        auto [ u, v] = q.front(); q.pop();
                        vector<int> dx= {1, -1, 0, 0};
                        vector<int> dy= {0, 0, -1, 1};
                        for(int index= 0;index< 4;index++)
                        {
                            int uu = u+dx[index];
                            int vv = v+dy[index];
                            if(uu<0 || vv<0 || uu>=n || vv>=m || vis[uu][vv] || grid[uu][vv]=='0') continue;
                            q.push({uu, vv});
                            vis[uu][vv] = 1;
                        }
                    }
                }
            }
        }
        return ans ;// number of islands.
        
    }
};
