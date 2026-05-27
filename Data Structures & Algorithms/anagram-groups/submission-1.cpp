class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for(string s: strs){
            vector<int> count(26, 0);
            for(char c: s){
                count[c-'a']++;
            }
            string key;
            for(int x: count)
                key += "#"+to_string(x);
            hash[key].push_back(s);
        }
        for(auto i: hash){
            ans.push_back(i.second);
        }
        return ans;
    }
};
