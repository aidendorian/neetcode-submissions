class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(char i: s){
            if(!check.empty()){
                if(check.top() == i-1 || check.top() == i-2)
                    check.pop();
                else
                    check.push(i);
            }
            else
                check.push(i);
        }
        return check.empty();
    }
};
