class MedianFinder {
public:
    vector<int> nums;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq_extra;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
        int k = nums.size();
        int len;
        if(k&1)len =(k+1)/2;    // 1-1 3-2 5- 3
        else len = k/2 +1;      // 2- 2 , 4- 3, 6- 4
        if(pq.empty() || (!pq.empty() && pq.top()>=num))
        {
            pq.push(num);
            while(pq.size()>len)
            {
                pq_extra.push(pq.top());
                pq.pop();
            }
        }
        else
        {
            pq_extra.push(num);
            while(pq.size()<len)
            {
                pq.push(pq_extra.top());
                pq_extra.pop();
            }
        }
    }
    
    double findMedian() {
        if((int)nums.size()&1)return (double)pq.top();
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a); pq.push(b);
        return (a+b)/(2*1.0);
    }
};