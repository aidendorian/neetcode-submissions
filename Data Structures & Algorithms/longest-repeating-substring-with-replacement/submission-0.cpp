class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        unordered_map <char, int> hash;
        int max_char = 0;
        for(int right = 0; right<n; right++){
            char c = s[right];
            hash[c] += 1;
            max_char = max(max_char, hash[c]);
            
            if((right-left+1-max_char)>k){
                hash[s[left]]--;
                left++;
            }
        }
        return n-left;
    }
};
