class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& v, vector<int>& target) {
        unordered_map<int, int> mp;
        bool a = false;
        bool b = false;
        bool c = false;
        int n = v.size();
        for(int i =0;i < n;i++)
        {
            if(v[i][0]<=target[0] && v[i][1]<=target[1] && v[i][2]<=target[2])
            {
                mp[i] = 1;
            }
        }
        for(auto [i, cnt]: mp)
        {
            if(v[i][0]==target[0])
            {
                a = true;
            }
            if(v[i][1]==target[1])
            {
                b= true;
            }
            if(v[i][2]==target[2])
            {
                c= true;
            }
        }
        return a&b&c;

    }
};
