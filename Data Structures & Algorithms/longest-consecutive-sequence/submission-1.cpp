class Solution {
public:
    class DSU{
        public:
        unordered_map<int, int> par;
        unordered_map<int, int> sz;
        int find(int root)
        {
            if(root==par[root]) return root;
            return par[root] = find(par[root]);
        }
        bool merge(int a, int b)
        {
            if(par.find(a)==par.end()) return false;
            a= find(a);
            b= find(b);
            if(a==b) return false;
            if(sz[b] > sz[a])swap(a, b);
            par[b] = a;
            sz[a]+=sz[b];
            return true;
        }
        void insert(int root)
        {
            par[root] = root;
            sz[root] = 1;
        }
    };
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;
        for(auto x: nums)
        {
            dsu.insert(x);
        }
        for(auto x: nums)
        {
            dsu.merge(x-1, x);
            dsu.merge(x+1, x);
        }
        int ans =0;
        for(auto x: nums)
        {
            ans = max(ans, dsu.sz[dsu.find(x)]);
        }
        return ans;
    }
};
