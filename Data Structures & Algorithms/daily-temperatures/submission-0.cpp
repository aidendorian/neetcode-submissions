class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono_dec;
        vector<int> ans(temperatures.size(), 0);
        int n = temperatures.size();
        for(int i = 0; i<n; i++){
            if(!mono_dec.empty()){
                while(!mono_dec.empty() && temperatures[mono_dec.top()]<temperatures[i]){
                    ans[mono_dec.top()] = i - mono_dec.top();
                    mono_dec.pop();
                }
                mono_dec.push(i);
            }
            else
                mono_dec.push(i);
        }
        return ans;
    }
};
