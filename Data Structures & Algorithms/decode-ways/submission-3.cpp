class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++)
        {
            if(i-1>=0)
            {
                string str = s.substr(i-1, 1);
                if(str!="0")
                {
                    dp[i]+=dp[i-1];
                }
            }
            if(i-2>=0)
            {
                string str = s.substr(i-2, 2);
                if(str.front()!='0' && stoi(str)<=26)
                dp[i]+=dp[i-2];
            }
           // cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};
