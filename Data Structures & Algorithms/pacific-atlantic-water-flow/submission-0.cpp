class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> dx = {1, -1,0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> count(n, vector<int>(m, 0));
        for(int i =0; i<n;i++)
        {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        for(int j =0;j<m;j++)
        {
            if(!vis[0][j])
            {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }
        while(!q.empty())
        {
            auto [u, v] = q.front();q.pop();
            count[u][v]++;
            for(int index = 0; index<4; index++)
            {
                auto uu = u+ dx[index];
                auto vv = v+ dy[index];
                if(uu< 0 || vv<0 || uu>=n || vv>=m || vis[uu][vv]|| nums[uu][vv]<nums[u][v]) continue;
                q.push({uu, vv});
                vis[uu][vv] = 1;
            }
        }
        vis.assign(n, vector<int>(m, 0));

        for(int i =0; i<n;i++)
        {
            q.push({i, m-1});
            vis[i][m-1] = 1;
        }
        for(int j =0;j<m;j++)
        {
            if(!vis[n-1][j])
            {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }
        while(!q.empty())
        {
            auto [u, v] = q.front();q.pop();
            count[u][v]++;
            for(int index = 0; index<4; index++)
            {
                auto uu = u+ dx[index];
                auto vv = v+ dy[index];
                if(uu< 0 || vv<0 || uu>=n || vv>=m || vis[uu][vv]|| nums[uu][vv]<nums[u][v]) continue;
                q.push({uu, vv});
                vis[uu][vv] = 1;
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(count[i][j]==2)ans.push_back({i, j});
            }
        }
        return ans;
        
    }
};
