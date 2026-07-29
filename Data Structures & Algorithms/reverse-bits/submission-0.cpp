class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i =0; i < 16; i++)
        {
            if((1 & (n>>i)) != (1&(n>>(31-i))))
            {
                n ^= (1<<i);
                n ^= (1<<(31-i));
            }
        }
        return n;
    }
};
