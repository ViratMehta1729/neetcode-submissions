class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int kk) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(kk+1, INT_MAX)));
        for(auto x: flights)
        {
            int u = x[0];
            int v = x[1];
            int cost = x[2];
            dp[u][v][0] = cost;
        }
        for(int k=1;k<=kk;k++)
        {
            for(int i=0; i<n;i++)
            {
                for(int j =0;j<n;j++)
                {
                    for(int stop =0;stop<n; stop++)
                    {
                       if(dp[i][stop][0] != INT_MAX &&
                            dp[stop][j][k-1] != INT_MAX)
                            {
                                dp[i][j][k] = min(
                                    dp[i][j][k],
                                    dp[i][stop][0] + dp[stop][j][k-1]
                                );
                            }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int k =0; k<=kk;k++)
        {
            ans= min(ans, dp[src][dst][k]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
