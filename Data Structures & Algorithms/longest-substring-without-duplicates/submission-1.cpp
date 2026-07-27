class Solution {
public:
    int fun(string &s)
    {
        int i =0;
        int j =0;
        map<int, int> mp;
        int ans = 0;
        int n = s.size();
        while(j< n)
        {
            mp[s[j]-'a']++;
            while(mp[s[j]-'a']>1)
            {
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)mp.erase(s[i]-'a');
                i++;
            }
            ans= max(ans, j-i+1);
            j++;
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s) {
        int ans =0;
        ans = fun(s);
        return ans;
    }
};
