class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(left<right){
            while(!isalnum(s[left]))
                left++;

            while(!isalnum(s[right]))
                right--;

            if((left < right) && (s[left] != s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
