class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> required;
        unordered_map<char, int> has;
        if(t.size()>s.size())
            return "";
        for(char i: t)
            required[i]++;
        int match = required.size();
        int l = 0;
        int n = s.size();
        int formed = 0;
        int min_len = INT_MAX;
        string best = "";

        for(int r=0; r<n; r++){
            char c = s[r];
            has[c]++;
            if(required.contains(c) && has[c]==required[c]){
                formed++;
            }
            if(formed==match){
                while((required.contains(s[l]) && has[s[l]]-1 >= required[s[l]]) || !required.contains(s[l])){
                    has[s[l]]--;
                    l++;
                }
                if(min_len>r-l+1){
                    min_len = r-l+1;
                    best = s.substr(l, min_len);
                }
            }
        }
        return best;
    }
};