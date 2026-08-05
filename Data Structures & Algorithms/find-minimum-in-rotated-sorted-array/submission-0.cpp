class Solution {
public:
    int findMin(vector<int> &nums) {
        int i =0;
        int j = nums.size()-1;
        int ans = INT_MAX;
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            if(nums[i]<nums[j])
            {
                ans = min(ans, nums[i]);
                j = i-1;
            }
            else if(nums[i] <= nums[mid])
            {
                ans=min(ans, nums[mid]);
                i = mid+1;
            }
            else
            {
                ans=min(ans, nums[mid]);
                j = mid-1;
            }
        }
        return ans;
    }
};
