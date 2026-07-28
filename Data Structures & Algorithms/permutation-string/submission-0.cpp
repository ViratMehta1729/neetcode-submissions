class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp1, mp2;
        for(auto x: s1)mp1[x]++;
        int k = s1.size();
        int i = 0;
        int j = 0;
        int n = s2.size();
        while(j<n)
        {
            mp2[s2[j]]++;
            while(j-i+1>k)
            {
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0)mp2.erase(s2[i]);
                i++;
            }
            if(j-i+1==k && mp1 == mp2)
            {
                return true;
            }
            j++;
        }
        return false;
    }
};
