class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMAX(n, 0);
        vector<int> rightMAX(n, 0);
        int maxLeft = 0;
        int maxRight = 0;
        for(int i=1;i<n;i++){
            if(height[i-1]>maxLeft){
                maxLeft = height[i-1];
                leftMAX[i] = maxLeft;
            }
            else
                leftMAX[i] = maxLeft;

            if(height[n-i]>maxRight){
                maxRight = height[n-i];
                rightMAX[n-i-1] = maxRight;
            }
            else
                rightMAX[n-i-1] = maxRight;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(min(leftMAX[i], rightMAX[i])-height[i]<0)
                continue;
            ans += min(leftMAX[i], rightMAX[i])-height[i];
        }
        return ans;
    }
};
