class Solution {
public:
    bool fun(vector<vector<int>> &v, int k)
    {
        int n = v.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        static vector<int> dx= {1, -1, 0, 0};
        static vector<int> dy= {0, 0, -1, 1};
        queue<pair<int, int>> q;
        if(v[0][0]<=k)
        {
            q.push({0, 0});
            vis[0][0] = 1;
        }
        while(!q.empty())
        {
            auto [u1, v1] = q.front();q.pop();
            for(int index=0;index<4;index++)
            {
                auto uu = u1+dx[index];
                auto vv= v1+dy[index];
                if(uu<0 || vv<0 || uu>=n || vv>=n || vis[uu][vv] || v[uu][vv]>k) continue;
                q.push({uu, vv});
                vis[uu][vv] = 1;
            }
        }
        return vis[n-1][n-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int i =0;
        int j = n*n-1;
        int ans = -1;
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            if(fun(grid, mid))
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};
