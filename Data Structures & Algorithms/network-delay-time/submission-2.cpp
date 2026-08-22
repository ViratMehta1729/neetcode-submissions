class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INT_MAX);
        for(auto x: times)
        {
            int u = x[0];
            int v = x[1];
            int t = x[2];
            graph[u].push_back({v, t});
        }
        dist[k] = 0;
        set<pair<int, int>> s;
        s.insert({0, k});
        while(!s.empty())
        {
            auto [d, u]= *s.begin();
            s.erase(s.begin());
            for(auto [v, t]: graph[u])
            {
                if(dist[v] > dist[u] + t) // dist[u] == d
                {
                    s.erase({dist[v], v}); // optimize
                    dist[v] = dist[u] + t;
                    s.insert({dist[v], v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i =1;i<=n;i++)
        {
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
