class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        for(int i =0;i<=k; i++)
        {
            vector<int> temp = dis;
            for(auto edge : flights)
            {
                auto u = edge[0];
                auto v = edge[1];
                auto cost = edge[2];
                if(dis[u]==INT_MAX) continue;
                if(temp[v] > dis[u]+cost)
                {
                    temp[v] = dis[u]+cost;
                }
            }
            dis = temp;
        }
        return dis[dst]==INT_MAX ? -1 : dis[dst];
    }
};
