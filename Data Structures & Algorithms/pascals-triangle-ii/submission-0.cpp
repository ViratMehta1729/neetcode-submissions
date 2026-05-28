class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0) return {1};
        if(n==1) return {1, 1};
        vector<int> temp (n+1, 0);
        temp[0] = 1;
        temp[1] = 1;
        for(int i =2; i<=n;i++)
        {
            int j = 1;
            int prev = 1;
            for(; j < i; j++)
            {
                temp[j]+=prev;
                prev = temp[j] - prev;
            }
            temp[j]= 1;
        }
        return temp;
    }
};