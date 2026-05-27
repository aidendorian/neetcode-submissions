class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n_dupe(nums.begin(), nums.end());
        unordered_map<int, int> hash;
        int max_len = 1;
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        for(int current: n_dupe){
            if(!n_dupe.count(current-1)){
                int x = 1;
                hash[current]++;
                while(n_dupe.count(current+x)){
                    hash[current]++;
                    x++;
                }
                if(max_len<hash[current])
                    max_len = hash[current];
            }
        }
        return max_len;
    }
};