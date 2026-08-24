class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if (n + m != k)
                    return false;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        // i ==0;
        for(int j = 1; j<=m;j++)
        {
            if(s2.substr(0, j)==s3.substr(0, j))dp[0][j][j]= 1;
        }
        // j == 0
        for(int i = 1; i<=n;i++)
        {
            if(s1.substr(0, i)==s3.substr(0, i))dp[i][0][i]= 1;
        }
        dp[0][0][0] = 1;
        for(int i =1;i<=n;i++)
        {
            for(int j =1; j<=m; j++)
            {
                for(int kk = 1;kk<=k;kk++)
                {
                    char a = s1[i-1];
                    char b = s2[j-1];
                    char c = s3[kk-1];
                    if(a==c)dp[i][j][kk]|=dp[i-1][j][kk-1];
                    if(b==c)dp[i][j][kk]|=dp[i][j-1][kk-1];
                }
            }
        }
        return dp[n][m][k];
        
    }
};
