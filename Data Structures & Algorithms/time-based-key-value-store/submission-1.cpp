class TimeMap {
    unordered_map <string, vector<pair<int, string>>> hash;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        auto& v = hash[key];
        int l = 0;
        int r = v.size() - 1;
        int mid = 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(v[mid].first <= timestamp){
                ans = v[mid].second;
                l = mid + 1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};