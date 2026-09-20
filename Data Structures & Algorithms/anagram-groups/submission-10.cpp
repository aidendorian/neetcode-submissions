class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for(const string &s: strs){
            string val = s;
            sort(val.begin(), val.end());
            hash[val].push_back(s);
        }
        for(const auto &[key, val]: hash)
            ans.push_back(val);
        return ans;
    }
};
