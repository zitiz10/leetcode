class Solution {
public:
    int maxProfit(vector<int>&arr) {
        int min_buy = arr[0];
        int profit = 0;
        for (int i = 1; i < arr.size(); i++) {
            int cost = arr[i] - min_buy;
            profit = max(profit, cost);
            min_buy = min(min_buy, arr[i]);
        }
        return profit;
    }
};