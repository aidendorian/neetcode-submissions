class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int, int> hash;
        for(const int &i: nums)
            hash[i]++;
        for(const auto &[key, val]: hash){
            freq[val].push_back(key);
        }
        for(int i = freq.size()-1; i>=0 && ans.size()<k; i--){
            for(const int &a: freq[i]){
                ans.push_back(a);
            }
        }
        return ans;
    }
};
