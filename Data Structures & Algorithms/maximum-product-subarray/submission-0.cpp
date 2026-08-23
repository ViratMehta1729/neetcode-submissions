class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 1));
        dp[1][0] = nums[0];
        dp[1][1] = nums[0];
        int ans = nums[0];
        for(int i =1;i<=n;i++)
        {
            if(nums[i-1]>0)
            {
                dp[i][0]= max(nums[i-1], nums[i-1]*dp[i-1][0]);
                dp[i][1] = min(nums[i-1], nums[i-1]*dp[i-1][1]);
            }
            else if(nums[i-1]==0)
            {
                dp[i][0] = 0;
                dp[i][1] = 0;
            }
            else
            {
                dp[i][0]= max(nums[i-1], nums[i-1]*dp[i-1][1]);
                dp[i][1] = min(nums[i-1], nums[i-1]*dp[i-1][0]);
            }
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};
