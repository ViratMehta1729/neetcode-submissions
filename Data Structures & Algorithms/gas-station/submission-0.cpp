class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1=0; int sum2 =0;
        for(auto x: gas)sum1+=x;
        for(auto y: cost)sum2+=y;
        if(sum2 > sum1) return -1;
        int n = cost.size();
        for(int i =0; i < n; i++)
        {
            int k = n;
            int j =i;
            int sum1=0;
            int sum2=0;
            bool flag = false;
            while(k--)
            {
                sum1+=gas[j];
                sum2+=cost[j];
                if(sum2> sum1)
                {
                    flag = true;
                    break;
                }
                j++;
                j=j % n;
            }
            if(!flag) return i;
        }
        return -1;
        
    }
};
