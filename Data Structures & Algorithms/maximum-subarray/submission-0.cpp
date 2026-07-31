class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i =1; i<n; i++)
        {
            curr = max(curr+nums[i], nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};
