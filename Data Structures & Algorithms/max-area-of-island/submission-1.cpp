class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m , 0));
        queue<pair<int, int>> q;
        int ans =0; // max area of grid
        for(int i =0;i< n;i++)
        {
            for(int j =0;j< m; j++)
            {
                if(vis[i][j] || !grid[i][j]) continue;
                int temp_ans = 0;
                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty())
                {
                    auto [u, v]= q.front();q.pop();
                    temp_ans++;
                    static vector<int> dx= {1, -1, 0, 0};
                    static vector<int> dy= {0, 0, -1, 1};
                    for(int index = 0;index< 4;index++)
                    {
                        int uu = u+dx[index];
                        int vv = v+dy[index];
                        if(uu<0 || vv<0 || uu>=n || vv>=m || vis[uu][vv] || !grid[uu][vv]) continue;
                        q.push({uu, vv});
                        vis[uu][vv] = 1;
                    }
                }
                ans = max(ans, temp_ans);

            }
        }
        return ans;
    }
};
