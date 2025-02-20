// O(logn)
// finding pivot element and applying binary search depending on if the target is to the left or right of pivot element

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int m = s + (e - s) / 2;
            if(nums[m] == target){
                return m;
            } 
            else if(nums[m] >= nums[s]){
                //landed to the left of pivot element
                if(target >= nums[s] && target < nums[m]){
                    //if target is to the left of pivot element
                    e = m - 1;
                } 
                else{
                    //if target is to the right of pivot element
                    s = m + 1;
                }
            } 
            else{
                //landed to the right of pivot element
                if(target > nums[m] && target <= nums[e]){
                    //if target is to the right of pivot element
                    s = m + 1;
                } 
                else{
                    //if target is to the left of pivot element
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};