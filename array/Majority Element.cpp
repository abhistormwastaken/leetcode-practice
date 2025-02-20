class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm
        // Just one idea why this algorithm works: Because this majority element occurs more than n/2 (floor value) times, even if other elements will 'vote against it', it will win
        int ans = 0, count = 0;
        for(int num : nums){
            if(count == 0) ans = num;
            count += ans == num ? 1 : -1;
        }
        return ans;
    }
};