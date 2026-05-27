class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs.size();i++){
            ans += to_string(strs[i].size())+"#"+strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.size()){
            if(s.empty())
                break;
            int delim = s.find('#', i);
            int n = stoi(s.substr(i, delim-i));
            ans.push_back(s.substr(delim+1, n));
            i = delim+n+1;
        }
        return ans;
    }
};
