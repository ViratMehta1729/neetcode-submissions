class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    void perm(vector<int> &nums, vector<int> &temp)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i =0;i< nums.size();i++)
        {
            if(mp.find(i)==mp.end())
            {
                mp[i]=1;
                temp.push_back(nums[i]);
                perm(nums, temp);
                temp.pop_back();
                mp.erase(i);
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        perm(nums, temp);
        return ans;
        
    }
};
