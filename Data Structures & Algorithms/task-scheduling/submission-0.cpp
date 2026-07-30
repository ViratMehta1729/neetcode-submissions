class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans =0;
        vector<int> fre(26, 0);
        for(auto x: tasks)
        {
            fre[x-'A']++;
        }
        priority_queue<int> pq;
        for(auto x: fre)
        {
            if(x) pq.push(x);
        }
        while(!pq.empty())
        {
            vector<int> temp;
            for(int i =0; i<=n; i++)
            {
                if (!pq.empty())
                {
                    auto x = pq.top(); pq.pop();
                    if(x-1)
                    temp.push_back(x-1);
                    ans++;
                }
                else
                {
                    if(!temp.size()) break;
                    ans++;
                }
            }
            if(temp.size())
            {
                for(auto x: temp)pq.push(x);
            }
        }
        return ans;
    }
};
