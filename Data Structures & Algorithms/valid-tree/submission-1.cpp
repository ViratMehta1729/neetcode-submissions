class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto x: edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            auto u = q.front();q.pop();
            for(auto v: graph[u])
            {
                if(vis[v]) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
        for(auto x: vis)
        {
            if(x==0) return false;
        }
        
        return edges.size() == n-1;
    }
};
