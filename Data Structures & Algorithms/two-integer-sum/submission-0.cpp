class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(hash.contains(nums[i])){
                ans.push_back(hash[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            hash[target - nums[i]] = i;
        }
    }
};
