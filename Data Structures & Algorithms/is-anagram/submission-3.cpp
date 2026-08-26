class Solution {
public:
    bool isAnagram(string s, string t) {
        int a = 0;
        int b = 0;
        unordered_map<int, int> mp;
        for(auto x: s){a|=(x-'a'); mp[x-'a']++;}
        for(auto x: t){b|=(x-'a');mp[x-'a']--;}
        if(a!=b) return false;
        for(auto [u, v]: mp)
        {
            if(v) return false;
        }
        return true;
    }
};
