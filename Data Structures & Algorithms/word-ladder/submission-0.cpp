class Solution {
public:
    bool Cantransform(string a, string b)
    {
        int cnt =0;
        for(int i =0;i< a.size();i++)
        {
            if(a[i]!=b[i])cnt++;
        }
        return cnt==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> graph(n);
        map<string, int> index;
        for(int i =0;i< n;i++)
        {
            index[wordList[i]] = i;
            for(int j = i+1;j<n;j++)
            {
                if(Cantransform(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        if(index.find(endWord)==index.end()) return 0;
        queue<int> q;
        vector<int> dist(n, INT_MAX);
        q.push(index[beginWord]);
        dist[index[beginWord]] = 1;
        while(!q.empty())
        {
            auto u = q.front();q.pop();
            for(auto v: graph[u])
            {
                if(dist[v] > 1+ dist[u])
                {
                  //  cout<<wordList[u]<<"->"<<wordList[v]<<endl;
                    dist[v] = 1+dist[u];
                    q.push(v);
                }
            }
        }
        return dist[index[endWord]]==INT_MAX ? 0 : dist[index[endWord]];
        
    }
};
