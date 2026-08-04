class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int res =0;
        sort(intervals.begin(), intervals.end());
        for(auto x: intervals)
        {
            if(ans.empty() || ans.back()[1] <= x[0])
            {
                ans.push_back(x);
            }
            else
            {
                res++;
                ans.back()[1] = min(ans.back()[1], x[1]);
            }
        }
        return res;
    }
};
