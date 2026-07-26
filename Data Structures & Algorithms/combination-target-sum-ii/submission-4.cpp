class Solution {
public:
    vector<vector<int>> ans;
    void comb(vector<int> &v, int index, int target, vector<int> &temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return ;
        }
        if(target<0) return ;
        for(int i = index; i< v.size(); i++)
        {
            while( i>index && i< v.size() && v[i]==v[i-1])i++;
            if(i==v.size()) break;
            temp.push_back(v[i]);
            comb(v, i+1, target-v[i], temp);
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(), v.end());
        vector<int> temp;
        comb(v, 0, target, temp);
        return ans;
        
    }
};
