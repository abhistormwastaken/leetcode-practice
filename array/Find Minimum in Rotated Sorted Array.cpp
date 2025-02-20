// O(n), O(1) - 2 pointers

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]) return nums[i];
        }
        return nums[0];
    }
};

// O(logn), O(1) - binary search

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};