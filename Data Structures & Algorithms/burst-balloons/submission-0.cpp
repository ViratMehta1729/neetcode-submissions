class Solution {
public:
    int fun(vector<int> &nums, int i)
    {
        int a, b, c;
        int n = nums.size();
        if(i-2==-1) a= 1;
        else a= nums[i-2];

        if(i==n) c= 1;
        else c= nums[i];
        b= nums[i-1];
        return a*b*c;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i =1;i<=n; i++)
        {
            dp[i][i] = fun(nums, i);
        }
        for(int p = 2; p<=n;p++)
        {
            for(int i =1 ; i+p-1<=n;i++)
            {
                int j = i+p-1;
                for(int k =i ; k <=j; k++)
                {
                    int a, b, c;
                    {
                        if(i-2==-1) a= 1;
                        else a= nums[i-2];

                        if(j==n) c= 1;
                        else c= nums[j];
                        b= nums[k-1];
                    }
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+a*b*c);
                }
                 
            }
        }
        return dp[1][n];
    }
};
