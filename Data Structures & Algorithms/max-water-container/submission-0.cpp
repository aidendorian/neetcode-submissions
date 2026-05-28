class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int vol = (right-left)*min(heights[left], heights[right]);
        while(left<right){
            int c_vol = (right-left)*min(heights[left], heights[right]);
            if(c_vol>vol){
                vol = c_vol;
                continue;
            }
            if(heights[left]>heights[right])
                right--;
            else
                left++;
        }
        return vol;
    }
};
