class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;
        int i =0;
        for(auto x: t)
        {
            if(s[i]==x)i++;
            if(i==s.size()) return true;
        }
        return false;
    }
};