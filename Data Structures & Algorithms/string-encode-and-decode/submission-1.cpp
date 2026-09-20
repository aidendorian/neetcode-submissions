class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string &s: strs)
            encoded += to_string(s.size()) + "#" + s;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.size()){
            int delim = s.find("#", i);
            int n = stoi(s.substr(i, delim-i));
            ans.push_back(s.substr(delim+1, n));
            i = delim+n+1;
        }
        return ans;
    }
};
