class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i =0;i< n;i++)
        {
            mp[s[i]]=i;
        }
        int ans =0;
        int index =0;
        int left = 0;
        vector<int> res;
        for(int i =0;i< n;i++)
        {
            if(i > index)
            {
                ans++;
                left = i;
            }
            index = max(index, mp[s[i]]);
            if(i==index)
            {
                res.push_back(i-left+1);
            }
        }
        return res;
        
    }
};
