class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
            
        unordered_map<char, int> hash_s;
        unordered_map<char, int> hash_t;

        for(const auto &c: s)
            hash_s[c]++;
        for(const auto &c: t)
            hash_t[c]++;

        if(hash_s == hash_t)
            return true;
        else
            return false;
    }
};
