class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        // ignore
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        auto ub = upper_bound(mp[key].begin(), mp[key].end(), make_pair(timestamp, "\xFF"));
        if(ub!=mp[key].begin())ub--;
        else
        {
            return "";
        }
        return ub->second;
    }
};
