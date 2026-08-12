class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // int current = 0;
        int left = 0;
        int right = 1;
        while (right < prices.size()) {
            int leftPrice = prices[left];
            int rightPrice = prices[right];
            profit = max(profit, (rightPrice - leftPrice)); 
            if (rightPrice - leftPrice < 0) {
                left = right;
            }
            right++;
        }

        return profit;
    }
};
