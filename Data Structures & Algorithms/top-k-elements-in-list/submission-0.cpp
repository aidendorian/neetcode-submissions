class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i: nums)
            freq[i]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& [n, c]: freq){
            bucket[c].push_back(n);
        }
        vector<int> ans;
        for(int i = bucket.size()-1; i>=0 && ans.size()<k; i--){
            for(int num : bucket[i])
        ans.push_back(num);
        }
        return ans;
    }
};
