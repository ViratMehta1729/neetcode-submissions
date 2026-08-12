class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n, 0);
        vector<vector<int>> graph(n);
        queue<int> q;
        for(auto x: pre)
        {
            graph[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        for(int i =0;i<n;i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        int cnt =0;
        while(!q.empty())
        {
            auto u = q.front();q.pop();
            cnt++;
            for(auto v: graph[u])
            {
                indeg[v]--;
                if(indeg[v]==0)q.push(v);
            }
        }
        return cnt==n;
    }
};
