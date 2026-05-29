class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        vector<int> freq(26, 0);
        vector<int> ans(26, 0);
        for (char i : s1) ans[i - 'a']++;
        int window_size = s1.size();
        int n = s2.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            freq[s2[r] - 'a']++;
            if (r - l + 1 == window_size) {
                if (ans == freq)
                    return true;
                else {
                    freq[s2[l]-'a']--;
                    l++;
                }
            }
        }
        return false;
    }
};