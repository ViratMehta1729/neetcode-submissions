class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int max_index=0;
        int local_max = 0;
        for(int i = 0;i< nums.size();i++)
        {
            if(max_index < i) return -1;
            local_max = max(local_max, i+ nums[i]);
            if(i==max_index && i !=nums.size()-1)
            {
                ans++;
                max_index = local_max;
            }
        }
        return ans;
    }
};
