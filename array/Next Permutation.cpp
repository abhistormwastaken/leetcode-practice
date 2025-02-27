class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            // going from right to left, find the first decreasing digit nums[index] (this means that the value from there to the right can be increased)
            int n = nums.size();
            int inflection_index = -1;
            for(int i = n - 2; i >= 0; i--){
                if(nums[i] < nums[i + 1]){
                    inflection_index = i;
                    break;
                }
            }
            if(inflection_index == -1){
                reverse(nums.begin(), nums.end());
                return;
            }
    
            //going from right to left again, find the first element that is greater than the value at 'index' and swap them
            for(int j = n - 1; j >= inflection_index; j--){
                if(nums[j] > nums[inflection_index]){
                    swap(nums[inflection_index], nums[j]);
                    break;
                }
            }
    
            // reverse the array to the right of 'index' since it would be already in descending order due to how our way of finding inflection point
            reverse(nums.begin() + inflection_index + 1, nums.end());
        }
    };

    // good example
    // inputs
    // 1542, 2541
    // outputs
    // 2145, 4125