class Solution {
public:
    bool canJump(vector<int>& nums) {
        int _max =0;
        for(int i =0;i<nums.size();i++)
        {
            if(_max < i) return false;
            _max = max(_max, i+nums[i]);
        }
        return true;
    }
};
