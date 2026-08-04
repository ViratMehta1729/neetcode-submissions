class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(auto x: nums)
        {
            if(ans.empty() || ans.back()[1] < x[0])
            {
                ans.push_back(x);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], x[1]);
            }
        }
        return ans;
    }
};
