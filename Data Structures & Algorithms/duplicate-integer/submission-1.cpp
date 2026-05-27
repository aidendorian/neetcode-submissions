class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto i: nums){
            if(!hash.contains(i)){
                hash.insert({i,0});
            }
            else
                return true;
        }
        return false;
    }
};