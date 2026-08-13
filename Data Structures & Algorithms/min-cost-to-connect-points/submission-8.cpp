class Solution {
public:
    class DSU{
        public:
        vector<int> par;
        vector<int> sz;
        DSU(int n)
        {
            par.resize(n+1);
            sz.resize(n+1, 1);
            for(int i=0;i<=n;i++)par[i]=i;
        }
        int find(int root)
        {
            if(root==par[root]) return root;
            return par[root] = find(par[root]);
        }
        bool merge(int a, int b)
        {
            a= find(a);
            b= find(b);
            if(a==b) return false;
            if(sz[b] > sz[a])swap(a, b);
            par[b] = a;
            sz[a]+=sz[b];
            return true;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edge;
        for(int i =0;i< n;i++)
        {
            for(int j =i+1; j<n;j++)
            {
                edge.push_back({i, j, abs(points[i][0]- points[j][0])+ abs(points[i][1]- points[j][1])});
            }
        }
        auto comp = [](auto &x, auto& y)
        {
            return x[2] < y[2];
        };
        sort(edge.begin(), edge.end(), comp);
        DSU dsu(n);
        int ans =0;
        int cnt = 0;
        for(auto x: edge)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if(dsu.merge(u, v)){ans+=wt;cnt++;}
            if(cnt==n-1) break;
        }
        return ans;
    }
};
