// trigger based 2 pointers

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0;
        int n = prices.size();
        int ans = 0;
        while(++right < n){
            ans = max(ans, prices[right] - prices[left]);
            if(prices[right] < prices[left]) left = right;
        }
        return ans;
    }
};


// kadane's algorithm - we'll convert it into a maximum subarray

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profit_loss;
        for(int i = 0; i < n - 1; i++){
            profit_loss.push_back(prices[i + 1] - prices[i]);
        }
        // prices = [7, 1, 5, 3, 6, 4]
        // now we have an array like this [-6, +4, -2, +3, -2]
        // can use kadane
        int ans = 0;
        int sum = 0;
        for(int x : profit_loss){
            sum += x;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};