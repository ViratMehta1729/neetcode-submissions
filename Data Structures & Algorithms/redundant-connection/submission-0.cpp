class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> size;
        DSU(int n)
        {
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i =0 ;i<=n;i++)
            {
                parent[i] = i;
            }
        }
        int find(int root)
        {
            if(root==parent[root]) return root;
            return parent[root] = find(parent[root]);
        }
        void merge(int a, int b)
        {
            a = find(a);
            b = find(b);
            if(a==b) return ;
            if(size[a]> size[b])swap(a, b);
            parent[b] = a;
            size[a]+=size[b];
            return ;
        }
        
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DSU dsu(n+1);
        for(auto x: edges)
        {
            if(dsu.find(x[0]) == dsu.find(x[1]))
            {
                ans = x;
            }
            dsu.merge(x[0], x[1]);
        }
        return ans;
    }
};
