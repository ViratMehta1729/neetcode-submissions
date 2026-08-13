class Solution {
public:
    class DSU {
    public:
        vector<int> par, sz;

        DSU(int n) {
            par.resize(n);
            sz.resize(n, 1);

            for(int i = 0; i < n; i++)
                par[i] = i;
        }

        int find(int x) {
            if(par[x] == x) return x;
            return par[x] = find(par[x]);
        }

        bool merge(int a, int b) {
            a = find(a);
            b = find(b);

            if(a == b) return false;

            if(sz[a] < sz[b])
                swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<array<int,3>> edges;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int wt =
                    abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);

                edges.push_back({wt, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);

        int ans = 0;
        int cnt = 0;

        for(const auto& e : edges) {
            int wt = e[0];
            int u  = e[1];
            int v  = e[2];

            if(dsu.merge(u, v)) {
                ans += wt;
                cnt++;

                if(cnt == n - 1)
                    break;
            }
        }

        return ans;
    }
};