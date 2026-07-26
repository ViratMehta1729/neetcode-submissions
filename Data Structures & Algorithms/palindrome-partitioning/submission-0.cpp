class Solution {
public:
    vector<vector<int>> ispal;
    vector<vector<string>> ans;
    void dfs(int index, string &s, vector<string> &temp)
    {
        if(index==s.size())
        {
            ans.push_back(temp);
        }
        for(int j = index; j < s.size();j++)
        {
            if(ispal[index][j])
            {
                temp.push_back(s.substr(index, j-index+1));
                dfs(j+1, s, temp);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        ispal.resize(n, vector<int>(n, 1));
        for(int k =2;k<=n;k++)
        {
            for(int i =0;i+k-1<n;i++)
            {
                int j = i+k-1;
                if(k==2)
                {
                    if(s[i]==s[j])ispal[i][j]=1;
                    else ispal[i][j] = 0;
                }
                else
                {
                    ispal[i][j] = ispal[i+1][j-1] & (s[i]==s[j]);
                }
            }
        }
        vector<string> temp;
        dfs(0, s, temp);
        return ans;
    }
};
