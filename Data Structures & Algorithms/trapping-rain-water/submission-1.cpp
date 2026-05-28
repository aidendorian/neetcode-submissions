class Solution {
public:
    int trap(vector<int>& height) {
        int right = height.size()-1;
        int left = 0;
        int maxL = height[left];
        int maxR = height[right];
        
        int ans = 0;
        while(left<right){
            if(maxR>maxL){
                left++;
                ans += max(0, maxL-height[left]);
                maxL = max(height[left], maxL);
            }
            else{
                right--;
                ans += max(0, maxR-height[right]);
                maxR = max(height[right], maxR);
            }
        }
        return ans;
    }
};