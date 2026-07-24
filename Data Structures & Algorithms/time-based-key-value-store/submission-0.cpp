class TimeMap {
public:
    // key -> {timestamp, value}
    std::unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        this->m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (this->m.count(key) == 0) return "";
        vector<pair<int, string>> v = this->m[key];
        
        int l = 0, r = v.size() - 1;
        while (l < r) {
            const int mid = l + (r - l) / 2;
            
            if (timestamp <= v[mid].first) r = mid;
            else l = mid + 1;
        }

        if (l < v.size() && v[l].first <= timestamp)
            return v[l].second;
        if (0 < l && v[l - 1].first < timestamp)
            return v[l - 1].second;
        return "";
    }
};
