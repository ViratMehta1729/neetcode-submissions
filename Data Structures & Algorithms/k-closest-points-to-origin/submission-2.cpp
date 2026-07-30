class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](auto x, auto y)
        {
            auto [x1, y1] = x;
            auto [x2, y2] = y;
            return abs(x1)*abs(x1) +abs(y1)*abs(y1) < abs(x2)*abs(x2) + abs(y2)*abs(y2);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;
        for(auto x: points)
        {
            pq.push({x[0], x[1]});
        }
        while(pq.size()>k)pq.pop();
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            auto [x, y]=pq.top(); pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};
