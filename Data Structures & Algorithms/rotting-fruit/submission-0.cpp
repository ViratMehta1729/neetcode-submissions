class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(int i =0;i<n;i++)
        {
            for(int j =0; j< m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int level = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [u, v] = q.front(); q.pop();
                for(int index= 0;index<4;index++)
                {
                    int uu = u + dx[index];
                    int vv = v+ dy[index];
                    if(uu<0 || vv<0 || uu>=n || vv>=m || grid[uu][vv]!=1) continue;
                    if(dist[u][v] + 1 < dist[uu][vv])
                    {
                        dist[uu][vv] = 1 + dist[u][v];
                        q.push({uu, vv});
                    }
                }
            }
            level++;
        }
        int ans = 0;
        for(int i =0;i< n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==0) continue;
                ans = max(ans, dist[i][j]);

            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
