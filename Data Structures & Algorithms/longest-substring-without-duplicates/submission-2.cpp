class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> hash;
        int left = 0;
        int count = 0;
        int n = s.size();
        for(int right = 0; right<n; right++){
            char c = s[right];
            if(hash.contains(c) && hash[c] >= left){
                left = hash[c]+1;
            }
            hash[c] = right;
            count = max(count, right-left+1);
        }
        return count;
    }
};
