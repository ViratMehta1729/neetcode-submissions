class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& num) {
        int left = num[0];
        int right= num[1];
        vector<vector<int>> ans;
        bool flag = true;
        for(auto id: v)
        {
            int x = id[0];
            int y = id[1];
            if(y < left)
            {
                ans.push_back({x, y});
            }
            else if( right < x)
            {
                if(flag)
                ans.push_back({left, right});
                ans.push_back({x, y});
                flag = false;
            }
            else
            {
                left = min(x, left);
                right = max(y, right);
            }
        }
        if(flag)
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};
