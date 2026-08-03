class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> fre;
        for(auto x: nums)
        {
            fre[x]++;
            if(fre[x]>1) return true;
        }
        return false;
    }
};