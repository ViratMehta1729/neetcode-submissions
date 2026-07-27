class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+2, 0);
        vector<int> right(n+2, 0);
        for(int i =0;i<n;i++)
        {
            left[i+1]=max(left[i], nums[i]);
        }
        for(int j=n-1;j>=0 ; j--)
        {
            right[j+1] = max(nums[j], right[j+2]);
        }
        int ans =0;
        for(int i =0;i<n;i++)
        {
            int l = left[i];
            int r = right[i+2];
            int k = min(r, l);
            if(k> nums[i])ans+=(k-nums[i]);
        }
        return ans;
    }
};
