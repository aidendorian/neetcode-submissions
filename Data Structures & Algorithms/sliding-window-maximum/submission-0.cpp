class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxHeld;
        int n = nums.size();
        vector<int> ans;
        for(int r = 0; r<n; r++){
            while(!maxHeld.empty() && maxHeld.front()<=r-k)
                maxHeld.pop_front();
            while(!maxHeld.empty() && nums[maxHeld.back()] <= nums[r])
                maxHeld.pop_back();
            maxHeld.push_back(r);
            if(r >= k - 1)
                ans.push_back(nums[maxHeld.front()]);
        }
        return ans;
    }
};
