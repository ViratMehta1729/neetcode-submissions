class Solution {
public:
    int reverse(int x) {
        if(!x) return 0;
        string ans;
        bool flag = false;
        if(x<0) flag = true;
        x= abs(x);
        while(x)
        {
            ans+=to_string(x%10);
            x/=10;
        }
        long long ret = flag?-stoll(ans):stoll(ans);
        if(ret == (int)(ret)) return ret;
        return 0;
    }
};
