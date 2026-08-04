/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& nums) {
        vector<pair<int, int>> helper;
        for(auto x: nums)
        {
            helper.push_back({x.start, 1});
            helper.push_back({x.end, -1});
        }
        sort(helper.begin(), helper.end());
        int res =0;
        int ans =0;
        for(auto x: helper)
        {
            res+=x.second;
            ans= max(ans, res);
        }
        return ans;
    }
};
