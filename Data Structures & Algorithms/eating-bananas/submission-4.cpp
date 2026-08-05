class Solution {
public:
    int fun(vector<int> &v, long long k)
    {
        long long ans =0;
        for(auto x: v)
        {
            ans += (x + k - 1) / k;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long i =1;
        long long j = *max_element(piles.begin(), piles.end());
        long long ans = -1;
        while(i<=j)
        {
            long long mid = i+(j-i)/2;
            if(fun(piles, mid)<=h)
            {
                ans= mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};
