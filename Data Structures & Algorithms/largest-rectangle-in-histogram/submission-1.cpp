class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            int curr = heights[i];
            while (l - 1 >= 0 && curr <= heights[l - 1]) l--;
            while (r + 1 <= n-1 && curr <= heights[r + 1]) r++;
            max_area = max(max_area, (r - l + 1) * curr);
        }
        return max_area;
    }
};