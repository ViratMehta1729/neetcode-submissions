class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        int cnt =0;
        for(auto x: nums)
        {
            if(!x)cnt++;
            mult*=x;
        }
        if(cnt>=2)
        {
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        else if (cnt==1)
        {
            vector<int> ans(nums.size(), 0);
            int index = -1;
            int cal = 1;
            for(int i =0;i< nums.size(); i++)
            {
                if(nums[i])cal*=nums[i];
                else index = i;
            }
            ans[index] = cal;
            return ans;
        }
        vector<int> ans(nums.size(), 0);
        for(int i =0 ; i< nums.size(); i++)
        {
            ans[i]= mult/nums[i];
        }
        return ans;
    }
};
