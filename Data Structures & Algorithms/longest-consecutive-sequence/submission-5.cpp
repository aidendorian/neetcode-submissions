class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exc(nums.begin(), nums.end());
        int max_len = 1;
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        for(const int &i: nums){
            if(!exc.count(i-1)){
                int len = 1;
                while(exc.count(i+len))
                    len++;
                if(max_len < len)
                    max_len = len;
            }
        }
        return max_len;
    }
};
