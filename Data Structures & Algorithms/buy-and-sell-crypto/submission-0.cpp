class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int left = prices[0];
        for(int i =1;i< prices.size();i++)
        {
            if(prices[i]> left)
            ans = max(ans, prices[i]-left);
            left = min(left, prices[i]);
        }
        return ans;
    }
};
