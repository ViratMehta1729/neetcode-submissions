class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int k =1; k<n; k++)
        {
            while(k+1<n && nums[k]==nums[k+1])k++;
            unordered_map<int, int> mp;

            for(int i =0;i< k;i++)
            {
                while(i+1<k && nums[i]==nums[i+1])
                {
                    mp[nums[i]]=1;
                    i++;
                }
                if(mp.find(-(nums[i]+nums[k]))!=mp.end())
                {
                    ans.push_back({-(nums[i]+nums[k]), nums[i], nums[k]});
                }
                mp[nums[i]] = 1;
            }

        }
        return ans;
    }
};
