class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int, int> mp;
        for(auto x: hand)mp[x]++;
        while(mp.size())
        {
            int start = mp.begin()->first;
            
            for(int i = start; i < start+k; i++)
            {
                if(mp.find(i)==mp.end()) return false;
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        }
        return true;
    }
};
