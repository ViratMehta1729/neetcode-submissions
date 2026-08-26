class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> count(n, vector<int>(26, 0));
        map<vector<int>, vector<int>> mp;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j < strs[i].size(); j++)
            {
                count[i][strs[i][j]-'a']++;
            }
            mp[count[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto &[u, v]: mp)
        {
            vector<string> temp;
            for(auto x: v)
            {
                temp.push_back(strs[x]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
