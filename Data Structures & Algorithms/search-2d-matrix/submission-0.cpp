class Solution {
public:
    int n, m;
    pair<int, int> pointer(int d)
    {
        return {d/m ,  d%m };
    }
    // int dist(pair<int, int> p)
    // {
    //     return p.first*m +p.second;
    // }
    bool searchMatrix(vector<vector<int>>& num, int target) {
        n = num.size();
        m = num[0].size();
        int i= 0;
        int j = m*n-1;
        while(i<=j)
        {
            
            int mid = i+(j-i)/2;
            auto [x, y] = pointer(mid);
            int k = num[x][y];
            if(k==target)
            {
                return true;
            }
            else if (k<target)
            {
                i = mid+1;
            }
            else
            {
                j=mid-1;
            }
           
        }
        return false;
    }
};
