class Solution {
public:
    vector<int> col;
    vector<int> row;
    vector<int> div;
    void set(int i, int j, int val)
    {
        col[j] |= (1<<val);
        row[i] |= (1<<val);
        int ii = i/3;
        int jj = j/3;
        int d = 3*ii + jj;
        div[d] |= (1<<val);
    }
    void unset(int i, int j , int val)
    {
        col[j] ^= (1<<val);
        row[i] ^= (1<<val);
        int ii = i/3;
        int jj = j/3;
        int d = 3*ii + jj;
        div[d] ^= (1<<val);

    }
    int check(int i, int j, int val)
    {
        int flag = 0;
        flag |= ((row[i]>>val)&1);
        flag |= ((col[j]>>val)&1);
        int ii = i/3;
        int jj = j/3;
        int d = 3*ii + jj;
        flag |= ((div[d]>>val)&1);
        return flag;
    }
    bool dfs(int i , int j, vector<vector<char>> &boards)
    {
        if(i==9 && j ==0) return true;
        int jj = j;
        int ii = i;
        if(j==8)
        {
            ii++; jj=0;
        }
        else
        {
            jj++;
        }
        if(boards[i][j]!='.')
        {
            if(dfs(ii, jj, boards)) return true;
        }
        else
        {
            for(int k =0;k<=8;k++)
            {
                if(check(i, j, k+1)) continue;
                boards[i][j] = '1'+k;
                set(i, j, k+1);
                if(dfs(ii, jj, boards)) return true;
                unset(i, j, k+1);
                boards[i][j] = '.';
            }
        }
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        col.resize(9, 0);
        row.resize(9, 0);
        div.resize(9, 0);
        for(int i =0; i<9; i++)
        {
            for(int j =0;j< 9; j++)
            {
                if(board[i][j]!='.')
                {
                    if(check(i, j, board[i][j]-'0')) return false;
                    set(i, j, board[i][j]-'0');
                }
            }
        }
         return true;
    }
};
