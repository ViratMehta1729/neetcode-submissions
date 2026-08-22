class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i =1;i<=n;i++)
        {
            dp[i][i] = 1;
        }
        int ans = 1 ;
        int index = 0;
        for(int k =2;k<=n;k++)
        {
            for(int i =1;i+k-1<=n; i++)
            {
                int j = i+k-1;
                if(s[i-1]==s[j-1]) dp[i][j] = ((k==2)? 1 : dp[i+1][j-1]);
                else dp[i][j] = 0;
                if(dp[i][j] && ans < j-i+1)
                {
                    ans = j-i+1;
                    index = i-1;
                }
            }
        }
        return s.substr(index, ans);
        
    }
};
