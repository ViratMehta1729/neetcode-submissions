class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for(auto x: nums)fre[x]++;
        priority_queue<pair<int, int>> pq;
        for(auto [x, y]: fre)
        {
            pq.push({y, x});        
        }
        vector<int> ans;
        while(ans.size()<k)
        {
            auto [u, v] = pq.top(); pq.pop();
            ans.push_back(v);
        }
        return ans;
    }
};
