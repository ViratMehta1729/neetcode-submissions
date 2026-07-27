class Solution {
public:
    vector<vector<string>> ans;
    vector<int>  col;
    vector<int> diag1;
    vector<int> diag2;
    void dfs(vector<string> &s, int r)
    {
        int n = s.size();
        if(r==n)
        {
            ans.push_back(s);
            return ;
        }
        for(int i =0 ; i< n;i++)
        {
            int d1 = r - i + n - 1;
            int d2 = r + i;

            if (col[i] || diag1[d1] || diag2[d2])
                continue;

            col[i] = diag1[d1] = diag2[d2] = 1;
            s[r][i] = 'Q';

            dfs(s, r + 1);

            s[r][i] = '.';
            col[i] = diag1[d1] = diag2[d2] = 0;
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s;
        col.resize(n, 0);
        diag1.resize(2*n-1, 0);
        diag2.resize(2*n-1, 0);
        for(int i =0;i<n;i++)
        {
            string temp;
            for(int j =0;j< n ; j++)
            {
                temp+='.';
            }
            s.push_back(temp);
        }
        dfs(s, 0);
        return ans;
        
    }
};
