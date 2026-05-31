class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> cal;

        for(string s: tokens){
            if(s=="+"){
                int l = cal.top();
                cal.pop();
                int f = cal.top();
                cal.pop();
                cal.push(f+l);
            }
            else if(s=="-"){
                int l = cal.top();
                cal.pop();
                int f = cal.top();
                cal.pop();
                cal.push(f-l);
            }
            else if(s=="/"){
                int l = cal.top();
                cal.pop();
                int f = cal.top();
                cal.pop();
                cal.push(f/l);
            }
            else if(s=="*"){
                int l = cal.top();
                cal.pop();
                int f = cal.top();
                cal.pop();
                cal.push(f*l);
            }
            else
                cal.push(stoi(s));
        }
        return cal.top();
    }
};
