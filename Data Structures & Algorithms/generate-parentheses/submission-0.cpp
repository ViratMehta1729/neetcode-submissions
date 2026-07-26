class Solution {
public:
    vector<string> ans;
    void dfs(string &s, int l, int r)
    {
        if(r<l) return ;
        if(l==0 && r==0)
        {
            ans.push_back(s);
            return ;
        }
        if(l>0)
        {
            s+='(';
            dfs(s, l-1, r);
            s.pop_back();
        }
        if(r>0)
        {
            s+=')';
            dfs(s, l, r-1);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(s, n, n);
        return ans;
        
    }
};
