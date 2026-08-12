class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);
        for(auto x: edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int cnt =0;
        for(int i =0;i<n;i++)
        {
            if(vis[i]) continue;
            cnt++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
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
        }
        return cnt;
    }
};
