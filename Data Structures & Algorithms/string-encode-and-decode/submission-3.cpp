class Solution {
public:

    string encode(vector<string>& strs) {
        string s ;
        for(auto x: strs)
        {
            s+=to_string(x.size());
            s+="@";
            s+=x;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i< s.size())
        {
            string sz;
            while(i< s.size() && s[i]!='@')
            {
                sz+=s[i++];
            }
            ans.push_back(s.substr(i+1, stoi(sz)));
            i+=stoi(sz);
            i++;
        }
        return ans;
    }
};
