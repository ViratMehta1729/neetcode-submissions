class Solution {
public:
    bool fun(map<char, int> mp1, map<char, int> mp2)
    {
        for(auto [u, v] : mp1)
        {
            if(mp2.find(u)==mp2.end()) return false;
            if(v > mp2[u]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char, int> mp1, mp2;
        for(auto x: t)
        {
            mp1[x]++;
        }
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = INT_MAX;
        int index = -1;
        while(j< n)
        {
            mp2[s[j]]++;
            cout<<i<<" "<<j<<endl;
            while(fun(mp1, mp2))
            {
                
                if(ans> j-i+1)
                {
                    ans=j-i+1;
                    index = i;
                }
                mp2[s[i]]--;
                i++;
            }
            j++;
        }
        if(ans==INT_MAX) return "";
        return s.substr(index, ans);
    }
};
