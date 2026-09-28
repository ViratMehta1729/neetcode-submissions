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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> temp;
        for(auto x: intervals)
        {
            int u= x.start;
            int v= x.end;
            temp.push_back({u, 1});
            temp.push_back({v, -1});
        }
        sort(temp.begin(), temp.end());
        int ans = 0;
        int cnt = 0;
        for(auto x: temp)
        {
            if(x.second==1)cnt++;
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
