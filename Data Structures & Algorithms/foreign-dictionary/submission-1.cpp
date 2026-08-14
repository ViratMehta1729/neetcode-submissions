class Solution {
public:
    vector<vector<int>> graph;
    vector<int> indeg;
    bool build(string a, string b)
    {
        int i =0;
        int j =0;
        while(i< a.size() && j < b.size())
        {
            if(a[i]!=b[j])
            {
                graph[a[i]-'a'].push_back(b[j]-'a');
                indeg[b[j]-'a']++;
                return false;
            }
            i++;
            j++;
        }
        return i < a.size();
    }
    string foreignDictionary(vector<string>& words) {
        graph.resize(26);
        indeg.resize(26, 0);
        int n = words.size();
        for(int i =0;i+1<n;i++)
        {

            if(build(words[i], words[i+1])) return "";
        }
        
        vector<int> count(26, 0);
        for(auto x: words)
        {
            for(auto y : x)
            {
                count[y-'a']++;
            }
        }
        queue<int> q;
        vector<int> ans;
        int cnt = 0;
        for(int i =0;i<26;i++)
        {
            if(indeg[i]==0 && count[i]>0)q.push(i);
            if(count[i]>0)cnt++;
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
        if(cnt !=ans.size()) return "";
        string res;
        for(auto x: ans)
        {
            res+=('a'+x);
        }
        return res;
    }
};
