class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> qq;
        for(int i =0;i< q.size(); i++)
        {
            qq.push_back({q[i], i});
        }
        sort(qq.begin(), qq.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int i =0;
        vector<int> ans(q.size(), -1);
        for(auto& [query, id] : qq)
        {
            while(i <  nums.size() && nums[i][0] <= query)
            {
                pq.push({nums[i][1]-nums[i][0]+1, nums[i][1]});
                i++;
            }

            while(!pq.empty() && pq.top().second < query)
            {
                cout<<i<<endl;
                pq.pop();

            }
            if(!pq.empty())
            {
                ans[id] = pq.top().first;
            }
        }
        return ans;
    }
};
