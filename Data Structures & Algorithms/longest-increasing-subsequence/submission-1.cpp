class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int x: nums)
        {
            auto lb = lower_bound(temp.begin(), temp.end(), x);
            if(lb==temp.end())temp.push_back(x);
            else
            {
                *lb =x;
            }
        }
        return temp.size();
    }
};
