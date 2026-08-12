class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        queue<int> q;
        vector<int> indeg(n);
        vector<int> ans;
        for(auto x: pre)
        {
            graph[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        for(int i =0;i<n;i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            auto u = q.front();q.pop();
            ans.push_back(u);
            for(auto v: graph[u])
            {
                indeg[v]--;
                if(indeg[v]==0)q.push(v);
            }
        }
        if(ans.size()==n) return ans;
        return {};
    }
};
