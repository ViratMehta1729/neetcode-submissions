class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int ans =0;
        for(int i =0;i< nums.size(); i++)
        {
            if(mp.find(nums[i]-1)!=mp.end())mp[nums[i]] = 1+ mp[nums[i]-1];
            else mp[nums[i]] = 1;
            ans = max(ans, mp[nums[i]]);
        }
        return ans;
    }
};
