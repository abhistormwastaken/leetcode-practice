class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // unlimited transactions but ONLY ONE STOCK can be held
        // so book profit on local maximas and wait to buy on local minimas
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};