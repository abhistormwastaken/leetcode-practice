class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane
        // why would you want to start by adding a negative number to the positive number
        // so we just don't. reset the current sum to 0 if you find that your it is negative
        int max_sum = nums[0];
        int curr_sum = 0;
        for(int num : nums){
            curr_sum = max(curr_sum, 0);
            curr_sum += num;
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};