class Solution {
public:
    map<vector<int>, bool> dp;
    bool fun(string &s, int index, int left, int right)
    {
        int n = s.size();
        if(index == n)
        {
            return left == right;
        }
        if(right > left) return false;
        if(dp.find({index, left, right})!=dp.end()) return dp[{index, left, right}];
        if(s[index]=='*')
        {
            if(fun(s, index+1, left, right) | fun(s, index+1, left+1, right) | fun(s, index+1, left, right+1)) return dp[{index, left, right}] = true;
        }
        else
        {
            if(s[index]=='(')
            {
                if(fun(s, index+1, left+1, right)) return dp[{index, left, right}]= true;
            }
            else
            {
                if(fun(s, index+1, left, right+1)) return dp[{index, left, right}] = true;
            }
        }
        return dp[{index, left, right}] =false;
    }
    bool checkValidString(string s) {
        stack<char> st;
        return fun(s, 0, 0, 0);
    }
};
