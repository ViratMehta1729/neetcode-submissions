class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(auto x: nums)sum+=x;
        
        int k = sum+target;
        if(k<0) return  0;
        if(k&1) return 0;
        k/=2;
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        for(auto x: nums)
        {
            for(int i = k; i>=x; i--)
            {
                dp[i]+=dp[i-x];
            }
        }
        return dp[k];
        
    }
};
