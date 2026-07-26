class Solution {
public:
    map<char, string> mp;
    vector<string> ans;
    void dfs(string &digits, int index, string &temp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(auto x: mp[digits[index]])
        {
            temp+=x;
            dfs(digits, index+1, temp);
            temp.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string s;
        dfs(digits, 0, s);
        return ans;
    }
};
