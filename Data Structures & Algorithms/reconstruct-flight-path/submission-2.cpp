class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> ans;
    void dfs(string u)
    {
        while(!graph[u].empty())
        {
            auto v = graph[u].begin();
            string next = *v;
            graph[u].erase(v);
            dfs(next);
        }
        ans.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x: tickets)
        {
            graph[x[0]].insert(x[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
