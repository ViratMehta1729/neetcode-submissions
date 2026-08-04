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
    bool canAttendMeetings(vector<Interval>& v) {
        auto comp= [](auto x, auto y)
        {
            return x.start < y.start;
        };
        sort(v.begin(), v.end(), comp);
        int right = -1;
        for(auto x: v)
        {
            if(right <= x.start)
            {
                right = x.end;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
