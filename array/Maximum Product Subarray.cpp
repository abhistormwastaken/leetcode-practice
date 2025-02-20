class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            result = max(result, nums[i]);
        }
        int currMax = 1;
        int currMin = 1;
        for (int n : nums) {
            if (n == 0) {
                currMax = 1;
                currMin = 1;
                continue;
            }
            int temp = n * currMax;
            currMax = max({n * currMin, n * currMax, n});
            currMin = min({temp, n * currMin, n});
            result = max(result, currMax);
        }
        return result;
    }
};


// max_element() finds pointer to max element in the vector and * dereferences it
// ----------------------------------------------------
// int result = *max_element(nums.begin(), nums.end());
// ----------------------------------------------------