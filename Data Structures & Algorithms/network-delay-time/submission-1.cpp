class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto x: times)
        {
            graph[x[0]].push_back({x[1], x[2]});
        }
        set<pair<int, int>> q;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        q.insert({0, k});
        while(!q.empty())
        {
            auto [wt, u] = *q.begin(); q.erase(q.begin());
            for(auto [v, w] : graph[u])
            {
                if(dist[v]> w + wt)
                {
                    q.erase({dist[v], v});
                    dist[v] = w + wt;
                    q.insert({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i =1;i<=n;i++)
        {
            ans = max(ans, dist[i]);
        }
        return ans==INT_MAX ? -1: ans;
    }
};
