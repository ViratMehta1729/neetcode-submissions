class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<pair<int, int>> st;
        int n = nums.size();
        vector<int> left(n, 0), right(n, n-1);
        for(int i =n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first>=nums[i])st.pop();
            if(!st.empty())right[i]= st.top().second-1;
            st.push({nums[i], i});
        }
        while(!st.empty())st.pop();
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && st.top().first>=nums[i])st.pop();
            if(!st.empty())left[i]=st.top().second+1;
            st.push({nums[i], i});
        }
        int ans =0;
        for(int i =0;i<n;i++)
        {
            ans= max(ans, (right[i]-left[i]+1)*nums[i]);
        }
        return ans;
    }
};
