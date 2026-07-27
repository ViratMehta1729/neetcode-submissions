class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans =0;
        for(int i =0;i<26;i++)
        {
            int l =0;
            int j =0;
            int cnt = 0;
            int n = s.size();
            while(j<n)
            {
                if((s[j]-'A')!=i)cnt++;
                while(cnt>k)
                {
                    if((s[l]-'A')!=i)cnt--;
                    l++;
                }
                ans= max(ans, j-l+1);
                j++;
            }
        }
        return ans;
    }
};
