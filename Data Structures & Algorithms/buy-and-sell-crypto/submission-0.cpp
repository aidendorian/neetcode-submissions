class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0;
        int profit = 0;
        for(int right=1;right<n;right++){
            if(prices[right]>prices[left]){
                profit = max(profit, prices[right]-prices[left]);
            }
            else
                left = right;
        }
        return profit;
    }
};
