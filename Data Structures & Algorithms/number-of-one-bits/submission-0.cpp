class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t k = n;
        int ans =0;
        while(k)
        {
            if(k&1)ans++;
            k>>=1;
        }
        return ans;
    }
};
