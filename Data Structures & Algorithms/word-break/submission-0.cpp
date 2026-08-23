class Solution {
public:
    map<string, bool> mp;
    map<int, bool> dp;
    bool fun(string &s, int index)
    {
        if(index == s.size()) return dp[index] = true;
        if(dp.find(index)!=dp.end()) return dp[index];
        string temp;
        for(int i = index ; i< s.size(); i++)
        { 
            temp+=s[i];
            if(mp.find(temp)==mp.end()) continue;
            if(fun(s, i+1))
            {
                dp[index] = true;
                return true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x: wordDict)mp[x]= true;
        return fun(s, 0);
        
    }
};
