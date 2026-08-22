class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0));
        int ans =0;
        for(int i =1;i<=n;i++)
        {
            dp[i][i]=1;
            ans++;
        }
        for(int k=2;k<=n;k++)
        {
            for(int i =1;i+k-1<=n;i++)
            {
                int j = i+k-1;
                if(s[i-1]==s[j-1])dp[i][j] = ((k==2)? 1: dp[i+1][j-1]);
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
