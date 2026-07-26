class Solution {
public:
    vector<vector<int>> ans;
    void comb(vector<int> &nums, int index, vector<int> &temp)
    {
        ans.push_back(temp);
        for(int i = index; i< nums.size(); i++)
        {
            if(i > index && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            comb(nums, i+1, temp);
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        comb(nums, 0, temp);
        return ans;
    }
};
