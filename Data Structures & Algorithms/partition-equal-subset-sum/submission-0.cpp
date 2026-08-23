class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(auto x: nums)sum+=x;
        if(sum&1) return false;
        vector<int> dp(sum/2+1, 0);
        dp[0] = 1;
        for(auto x: nums)
        {
            for(int j = sum/2 ; j>=x; j--)
            {
                dp[j]|=dp[j-x];
            }
        }
        return dp[sum/2];
    }
};
