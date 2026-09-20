class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i: nums){
            if(hash.contains(i))
                return true;
            hash.emplace(i, 0);
        }
        return false;
    }
};