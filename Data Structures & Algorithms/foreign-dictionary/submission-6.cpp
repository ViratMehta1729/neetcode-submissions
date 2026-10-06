class Solution {
public:
    pair<int, int> fun(string &s1, string &s2)
    {
        int i =0;
        int j =0;
        while(i< s1.size() && j < s2.size())
        {
            if(s1[i]!=s2[j]) return {s1[i]-'a', s2[j]-'a'};
            i++;
            j++;
        }
        if(i < s1.size()) return {-1, 0};
        return {-1, -1};
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> graph(26);
        vector<int> indeg(26, 0);
        unordered_map<int, int> mp;
        for(int i = 1; i<words.size(); i++)
        {
            auto [u, v] = fun(words[i-1], words[i]);
            if(u!=-1 && v!=-1)
            {
                if(u!=v)
                {
                    graph[u].push_back(v);
                    indeg[v]++;
                }
            }
            else if(u==-1 && v==0)
            {
                return "";
            }
            for(auto x: words[i-1])mp[x-'a']=1;
            
        }
        for(int i =0;i<words.size(); i++)
        {
            for(auto x: words[i])mp[x-'a']=1;
        }
        queue<int> q;
        for(int i = 0; i<26; i++)
        {
            if(mp.find(i)==mp.end())continue;
            if(!indeg[i])q.push(i);
        }
        string ans;
        while(!q.empty())
        {
            auto root = q.front();q.pop();
            ans+='a'+root;
            for(auto child: graph[root])
            {
                indeg[child]--;
                if(!indeg[child])
                {
                    q.push(child);
                }
            }
        }
        if(mp.size()!=ans.size()) return "";
        return ans;
    }
};
