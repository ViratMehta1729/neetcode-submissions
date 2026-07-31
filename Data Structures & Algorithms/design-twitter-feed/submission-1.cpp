class Twitter {
public:
    unordered_map<int, unordered_set<int>> graph;
    unordered_map<int, vector<vector<int>>> post;
    int timer = 0; // Usually this should be under lock for overlapping postTweet
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({timer++, (int)post[userId].size(), userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> temp;
        if(post[userId].size())temp.push(post[userId][post[userId].size()-1]);
        for(auto id : graph[userId])
        {
            if(post[id].size())temp.push(post[id][post[id].size()-1]);
        }
        vector<int> ans;
        int k = 10;
        while(k-- && !temp.empty())
        {
            auto res = temp.top(); temp.pop();
            ans.push_back(res[3]);
            int id = res[2];
            int index = res[1];
            if(index -1 >=0)
            {
                temp.push(post[id][index-1]);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        graph[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        graph[followerId].erase(followeeId);
        
    }
};
