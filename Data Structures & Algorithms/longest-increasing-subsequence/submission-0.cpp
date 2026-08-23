class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for(int x: nums)
        {
            auto lb = s.lower_bound(x);
            if(lb==s.end())s.insert(x);
            else
            {
                s.erase(lb);
                s.insert(x);
            }
        }
        return s.size();
    }
};
