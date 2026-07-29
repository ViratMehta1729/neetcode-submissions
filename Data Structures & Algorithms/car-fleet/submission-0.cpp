class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, double>> v;
        int n = pos.size();
        for(int i =0;i< n;i++)
        {
            v.push_back({pos[i], (target-pos[i])/(1.0 * speed[i])});
        }
        sort(v.begin(), v.end());
        stack<double> st;
        int ans =0;
        for(int i = n-1;i>=0 ; i--)
        {
            while(!st.empty() && st.top()<v[i].second)st.pop();
            if(st.empty())ans++;
            st.push(v[i].second);
        }
        return ans;
    }
};
