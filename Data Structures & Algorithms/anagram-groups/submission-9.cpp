class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for(const auto &s: strs){
            vector<int> freq(26, 0);
            for(const auto &c: s)
                freq[c-'a']++;
            string key = "";
            for(const auto &i: freq)
                key += i;
            hash[key].push_back(s);
        }
        for(const auto &[key, val]: hash)
            ans.push_back(val);
        return ans;
    }
};
