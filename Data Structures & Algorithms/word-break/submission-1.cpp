class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> mp;
        for(auto  item : wordDict) mp[item] = true;
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i =1;i<=n; i++)
        {
            string temp;
            for(int j = i; j >=1 && (i-j+1)<=20; j--)
            {
                temp=s.substr(j-1, i-j+1);
                if(mp.find(temp)==mp.end()) continue;
                dp[i]=dp[i] | dp[j-1];
            }
        }
        return dp[n];
    }
};
