class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n_dupe(nums.begin(), nums.end());
        int max_len = 1;
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        for(int current: n_dupe){
            if(!n_dupe.count(current-1)){
                int len = 1;
                while(n_dupe.count(current+len)){
                    len++;
                }
                if(max_len<len)
                    max_len = len;
            }
        }
        return max_len;
    }
};