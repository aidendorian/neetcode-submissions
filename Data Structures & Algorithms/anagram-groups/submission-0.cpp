class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for(auto i: strs){
            string sorted_i = i;
            sort(sorted_i.begin(), sorted_i.end());
            hash[sorted_i].push_back(i);
        }
        for(auto i: hash){
            ans.push_back(i.second);
        }
        return ans;
    }
};
